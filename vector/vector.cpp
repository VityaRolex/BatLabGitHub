#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <exception>

struct Word
{
public:
    std::string text;
    size_t quontity;
    Word(const std::string& _text) : text(_text), quontity(1) {}
};

void CheckFile(std::ifstream& is)
{
    if (!is.is_open())
        throw std::runtime_error("\nFile din`t open!\n");
    if (!is.good())
        throw std::runtime_error("\nFile stream is bad!\n");
    if(is.peek() == EOF)
        throw std::runtime_error("\nFile is a empty!\n");
}


int main()
{
    try
    {
        std::string delim = {" .,"};
        std::string buffer;
        std::string word;
        std::vector<Word> result;
        std::ifstream is("text.txt", std::ios::in);
        
        CheckFile(is);
        while (std::getline(is, buffer))
        {
            size_t start{};

            while (true)
            {
                size_t end = buffer.find_first_of(delim, start);

                std::string word = buffer.substr(start, end - start);

                if (!word.empty())
                {
                    bool found = false;
                    for (auto &w : result)
                    {
                        if (w.text == word)
                        {
                            w.quontity++;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        Word temp(word);
                        result.push_back(temp);
                    }
                }
                if (end == std::string::npos)
                    break;
                start = ++end;
            }
        }
        for (size_t i{}; i < result.size(); ++i)
        {
            std::cout << (result.at(i)).text << ' ' << (result.at(i)).quontity << '\n';
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}