#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    vector<string> currentLine;
    int currentWidth = 0;

    for(const auto& word : words) {
        if ((currentWidth + word.length() + currentLine.size()) > maxWidth) {
            string justifiedLine = "";

            // calculate spaces needed
           if (currentLine.size() == 1) {
               // for single word line
               justifiedLine = currentLine[0];
               justifiedLine.append(maxWidth - justifiedLine.length(), ' ');
           } else {
                // for multi word line
                int spacesNeeded = maxWidth - currentWidth;
                // get gaps between word
                int gaps = currentLine.size() - 1;

                // calculate base space and extra space
                int spacesPerGap = spacesNeeded / gaps;
                int extraSpaces = spacesNeeded % gaps;

                justifiedLine = currentLine[0];

                // start from 1 bcs the justifiedLine already contains first element
                for(size_t i = 1; i < currentLine.size(); ++i) {
                    int spaces = spacesPerGap + (i <= extraSpaces ? 1 : 0);
                    justifiedLine.append(spaces, ' ');
                    justifiedLine.append(currentLine[i]);
                }

           }

           // add current line to results
           result.push_back(justifiedLine);
           // reset for new line
           currentLine.clear();
           currentWidth = 0;
           currentLine.push_back(word);
           currentWidth += word.length();
        }
        else {
            currentLine.push_back(word);
            currentWidth += word.length();

        }
    }

    // handle last line
    if (!currentLine.empty()) {
        string lastLine = currentLine[0];
        // join remaining word with single space
        for(size_t i = 1; i < currentLine.size(); ++i) {
            lastLine.append(" ");
            lastLine.append(currentLine[i]);
        }
        // pad with spaces to reach maxWidth
        lastLine.append(maxWidth - lastLine.length(), ' ');
        result.push_back(lastLine);
    }

    return result;
}


int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> justifiedText = fullJustify(words, maxWidth);

    //for (const string& line : justifiedText) {
    //    std::cout << line << std::endl;
    //}
    //
    for (int a=0; a < justifiedText.size(); a++) {
        cout << justifiedText[a] << endl;
    }

    return 0;
}
