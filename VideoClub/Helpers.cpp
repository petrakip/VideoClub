#include "Helpers.h"
#include <map>
#include <cctype>
#include <string>
#include <algorithm>

void splitString(string s, string delimiter, vector<string>* target)
{
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        target->push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    target->push_back(s);
}

string join(vector<string> source, string delimiter)
{
    string result = "";
    for (string item : source) {
        result += delimiter + item;
    }
    return result.substr(delimiter.length());
}

int drawWrappedText(float pos_x, float pos_y, float size, int width, const string& text, const graphics::Brush& brush)
{
    const float averageBoxWidth = 1.2;
    const float averageBoxHeight = 1.2;

    int letterWidth = size * averageBoxWidth;
    int letterHeight = size * averageBoxHeight;
    int maxLetters = width / letterWidth;
    
    float currentPosY = pos_y;
    string currentLine = "";
    string currentWord = "";
    
    for (char letter : text) {
        if (letter == ' ' || letter == '\t' || letter == '\n' || letter == '\r') {
            currentLine = currentLine + currentWord + letter;
            currentWord = "";
            continue;
        }

        currentWord += letter;

        if (currentLine.length() + currentWord.length() > maxLetters) {
            graphics::drawText(pos_x, currentPosY, size, currentLine, brush);
            currentPosY += letterHeight;
            currentLine = "";
        }
    }

    currentLine += currentWord;
    graphics::drawText(pos_x, currentPosY, size, currentLine, brush);

    return (currentPosY + letterHeight) - pos_y;
}

std::string toLowerCase(std::string input)
{
    std::string result;
    result.resize(input.size());

    std::transform(input.begin(), input.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });
    
    return result;
}
