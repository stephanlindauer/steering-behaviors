#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>

namespace steering_behaviors {

class Random {

public:

    static int random(int limit) {
        if (useRandomOrg) {

        }

        return rand() % limit;
    }

    static void setInternal(void) {
        useRandomOrg = false;
    }

    static void setRandomOrg(void) {
        useRandomOrg = true;
    }

private:

    static bool useRandomOrg;

};

}

#endif // RANDOM_H
