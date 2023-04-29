#include <iostream>
#include <string>

using std::string, std::cout, std::endl;
using std::ostream;

namespace slice {
    
    class string : public std::string {
        struct slice {
            char *data;
            int len;
        };
    public:

        string() : std::string() {}
        string(const char* str) : std::string(str) {}
        string(std::string str) : std::string(str) {}

        string operator()(int a, int b, int step = 1) {
            // substring logic
            if (step == 0) {
                std::cerr << "slice step cannot be 0" << endl;
                exit(1);
            }
            int len = this->size();
            if (a < 0 || len < b) {
                std::cerr << "please stay in bounds. thx" << endl;
                exit(1);
            }

            string result;
            auto itr = this->cbegin() + a;
            auto stop = this->cbegin() + b;
            while(step > 0 ? itr + step <= stop : itr + step >= stop) {
                result.push_back(*itr);
                itr += step;
            }

            return result;
        }
    };

};

int main(int argc, char **argv) {
    slice::string str = "Thisais a test";
    cout << str << endl;

    cout << str(0,5,1) << endl;
    cout << str(5,0,-1) << endl;
    cout << str(1,1) << endl;

    return 0;
}
