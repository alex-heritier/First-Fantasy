//
//  TextFormatter.cpp
//  First Fantasy
//
//  Created by Alex on 11/9/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>
#include <vector>

#include "TextFormatter.hpp"

struct Line {
    Line(std::string line, int ll): mLine(line), mLineLength(ll) {}
    
    void prependText(std::string &text)
    {
        mLine.insert(0, text);
    }
    
    std::string adjust()
    {
        for (int i = mLine.length() - 1; i >= 0; i--) {
            if (i <= mLineLength && mLine.at(i) == ' ') {
                std::string result = mLine.substr(i, std::string::npos);
                mLine.erase(i, std::string::npos);
                return result;
            }
        }
    }
    
    int mLineLength;
    std::string mLine;
};

struct Paragraph {
    Paragraph(std::string rawParagraph, int lc, int ll): mLineCount(lc), mLineLength(ll)
    {
        for (int i = 0; i < lc && i < rawParagraph.length(); i += mLineLength) {
            mLines.push_back(Line(rawParagraph.substr(i, mLineLength), mLineLength));
        }
    }
    
    void prependText(std::string &text)
    {
        mLines[0].prependText(text);
    }
    
    std::string adjust()
    {
        std::string carry;
        for (int i = 0; i < mLines.size(); i++) {
            Line &line = mLines[i];
            
            line.prependText(carry);
            carry = line.adjust();
        }
        return carry;
    }
    
    int mLineCount;
    int mLineLength;
    std::vector<Line> mLines;
};

struct Essay {
    Essay(std::string rawEssay, int lc, int ll): mLineCount(lc), mLineLength(ll)
    {
        int paragraphLength = ll * lc;
        for (int i = 0; i < rawEssay.length(); i += paragraphLength) {
            mParagraphs.push_back(Paragraph(rawEssay.substr(i, paragraphLength), lc, ll));
        }
    }
    
    std::string adjust()
    {
        std::string carry;
        for (int i = 0; i < mParagraphs.size(); i++) {
            Paragraph &paragraph = mParagraphs[i];
            
            paragraph.prependText(carry);
            carry = paragraph.adjust();
        }
        
        if (!carry.empty()) {
            Paragraph p(carry, mLineCount, mLineLength);
            p.adjust();
            mParagraphs.push_back(p);
        }
    }
    
    int mLineCount;
    int mLineLength;
    std::vector<Paragraph> mParagraphs;
};

namespace ff {
    
    TextFormatter::TextFormatter(std::string &rawText, int lineCount, int lineLength):
        mRawText(rawText),
        mLineCount(lineCount),
        mLineLength(lineLength)
    {}
    
    Essay &TextFormatter::getFormattedText()
    {
        mEssay = Essay(mRawText, mLineCount, mLineLength);
        return mEssay;
    }
}
