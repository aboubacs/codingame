#include "Util.h"

namespace Util {

    string StringBigNumber(long long int number) {
        /*auto suffix = {"", "K", "M", "G", "kG", "mG", "gG"};
        int c = 0;
        while (number >= 1000) {
            number /= 1000;
            c++;
        }
        string result = to_string(number);
        while (result.size() != 4) result += " ";
        result += suffix;
        return result;*/

        return to_string(number);
    }
}