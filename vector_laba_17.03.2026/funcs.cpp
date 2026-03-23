#include"header.h"


void inputVector(std::vector<int>& v, std::istream& in)
{
    std::cout << "Введите числа в вектор через пробел или через enter, когда закончите, введите любой нечисловой символ.\n";
    int buffer{};
    while(in >> buffer)
    {
        v.push_back(buffer);
    }
}


void clearInput(std::istream& in)
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int countSum(std::vector<int>& v)
{
    int res{};
    for (int i{}; i < v.size(); ++i)
    {
        res += v.at(i);
    }
    return res;
}


size_t countNumsEqualTo(std::vector<int>& v, int n)
{
    size_t res{};
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i) == n)
        {
            ++res;
        }
    }
    return res;
}


int countAverage(std::vector<int>& v)
{
    return (countSum(v))/v.size();
}


void changeZerosToAverage(std::vector<int>& v)
{
    int av = countAverage(v);
    for(int i{}; i < v.size(); ++i)
    {
        if (v.at(i) == 0)
        {
            v.at(i) = av;
        }
    }
}


int countSumFromAToB(std::vector<int>& v, size_t A, size_t B)
{
    int res{};
    if (A > B || A < -1 || B > v.size() + 1)
    {
        throw std::runtime_error("a");
    }
    for (size_t i{A}; i < B; ++i)
    {
        res += v.at(i);
    }
    return res;
}


void addToEveryElementOfVectorSumOfVectorFromAToB(std::vector<int>& v, size_t A, size_t B)
{
    int sum = countSumFromAToB(v, A, B);
    for(int i{}; i < v.size(); ++i)
    {
        v.at(i) += sum;
    }
}


void changeEvenToMaxMinusMin(std::vector<int>& v)
{
    int max{v.at(0)};
    int min{v.at(0)};
    int minus{};
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i) < min)
        {
            min = v.at(i);
        }
        if (v.at(i) > max)
        {
            max = v.at(i);
        }
    }
    minus = max - min;
    for (int i{}; i < v.size(); ++i)
    {
        if (std::abs(v.at(i)) % 2 == 0)
        {
            v.at(i) = minus;
        }
    }
}


void deleteAllEqualOnModuleSaufFirst(std::vector<int>& v)
{
    for (int i{}; i < v.size(); ++i)
    {
        for (int j{i + 1}; j < v.size(); ++j)
        {
            if (v.at(j) == v.at(i))
            {
                v.erase(v.begin() + j);
                --j;
            }
        }
    }
}


void openStream(std::ifstream& in, const char* name)
{
    in.close();
    in.open(name, std::ios::in);
    if(!in.is_open())
    {
        throw std::runtime_error("b");
    }
    if(in.peek() == EOF)
    {
        throw std::runtime_error("c");
    }
}


void readStringsFromFile(std::vector<std::string>& v, std::ifstream& in)
{
    std::string temp{};
    while(in.peek() != EOF)
    {
        std::getline(in, temp);
        v.push_back(temp);
    }
}


void sortVector(std::vector<std::string>& v)
{
   
}


void printVector(std::vector<std::string>& v)
{
    for(int i{}; i < v.size(); ++i)
    {
        std::cout << v.at(i) << '\n';
    }
}


void printOnLetter(std::vector<std::string>& v, char c)
{
    for(int i{}; i < v.size(); ++i)
    {
        if(v.at(i)[0] == std::toupper(c) || v.at(i)[0] == std::tolower(c))
        {
            std::cout << v.at(i) << '\n';
        }
    }
}


void deleteOnLetter(std::vector<std::string>& v, char c)
{
    for(int i{}; i < v.size(); ++i)
    {
        if(v.at(i)[0] == std::toupper(c) || v.at(i)[0] == std::tolower(c))
        {
            v.erase(v.begin() + i);
            --i;
        }
    }
}


bool operator <(Time& left, Time& right)
{
    if (left.hours > right.hours)
    {
        return true;
    }
    if (left.hours == right.hours && left.minutes < right.minutes)
    {
        return true;
    }
    return false;
}


bool operator ==(Time& l, Time& r)
{
    return (r.hours == l.hours && r.minutes == l.minutes);
}


bool operator <=(Time& l, Time& r)
{
    return (l < r || l == r);
}


bool operator !=(Time& l, Time& r)
{
    return !(l == r);
}


std::istream& operator >> (std::istream& in, Time& time)
{
    in >> time.hours;
    in.ignore();
    in >> time.minutes;
    return in;
}


std::istream& operator >> (std::istream& in, Train& train)
{
    in >> train.number;
    in.ignore();
    getline(in, train.end, ';');
    in.ignore();
    std::string temp;
    getline(in, temp, ';');
    if(temp == "Passenger")
    {
        train.type = Type::Passenger;
    }
    else
    {
        train.type = Type::Fast;
    }
    in >> train.starting_time;
    in.ignore();
    in >> train.in_road_time;
    in.ignore();
    return in;
}

void optimizeTime(Time& time)
{
    while(time.minutes >= 60)
    {
        ++time.hours;
        time.minutes -= 60;
    }
}

std::ostream& operator << (std::ostream& out, Time& time)
{
    out << time.hours << ":" << time.minutes;
    return out;
}

void inputFromFile(std::vector<Train>& v, std::ifstream& in)
{
    Train temp;
    while(in.peek() != EOF)
    {
        in >> temp;
        v.push_back(temp);
    }
}


void sortByStartTime(std::vector<Train>& v)
{
    std::sort(v.begin(), v.end(), [](Train& a, Train& b){return a.starting_time < b.starting_time;});
}

std::ostream& operator << (std::ostream& out, Train& obj)
{
    out << "Number: " << obj.number << " Ending Station: "<< obj.end << " Train Type: " << (obj.type == Type::Passenger ? "Passenger" : "Fast") << " Starting Time: " << obj.starting_time << " In road time: " << obj.in_road_time << '\n';
    return out;
}

void outputTrainBehingTimes(std::vector<Train>& v, Time& left, Time& right)
{
    if (right < left)
    {
        throw std::runtime_error("d");
    }
    for (int i{}; i < v.size(); ++i)
    {
        if (left < v.at(i).starting_time && v.at(i).starting_time < right)
        {
            std::cout << v.at(i);
        }
    }
}


void outputTrainsInSameEnd(std::vector<Train>& v, std::string& end)
{
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i).end == end)
        {
            std::cout << v.at(i);
        }
    }
}


void outputFastTrainsInSameEnd(std::vector<Train>& v, std::string& end)
{
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i).end == end && v.at(i).type == Type::Fast)
        {
            std::cout << v.at(i);
        }
    }
}


Train& searchFastestTrainInCertainEnd(std::vector<Train>& v, std::string& end)
{
    int res_idx{-5};
    int i{};
    Time temp{0,0};
    Time minTime{0,0};
    while(i < v.size() && res_idx == -5)
    {
        if(v.at(i).end == end)
        {
            res_idx = i;
            minTime = v.at(i).starting_time;
            minTime.minutes += v.at(i).in_road_time;
            optimizeTime(minTime);
        }
        ++i;
    }
    while(i < v.size())
    {
        temp = v.at(i).starting_time;
        temp.minutes += v.at(i).in_road_time;
        optimizeTime(temp);

        if (v.at(i).end == end && temp < minTime)
        {
            res_idx = i;
            minTime = temp;
        }
        ++i;
    }
    return v.at(res_idx);
}



