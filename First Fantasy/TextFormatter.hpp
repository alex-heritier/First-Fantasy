//
//  TextFormatter.hpp
//  First Fantasy
//
//  Created by Alex on 11/9/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef TextFormatter_hpp
#define TextFormatter_hpp

#include <vector>

namespace ff {
    class TextFormatter {
    public:
        TextFormatter(std::string &, int, int);
        std::vector<std::vector<std::string> > &getFormattedText();
    private:
        std::string mRawText;
        int mLineCount;
        int mLineLength;
        Essay mEssay;
    };
}

#endif /* TextFormatter_hpp */
