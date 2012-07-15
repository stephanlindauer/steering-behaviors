#ifndef RANDOM_H
#define RANDOM_H

namespace steering_behaviors {

class Random {

public:
    static int random(int limit);
    static void setInternal(void);
    static void setRandomOrg(void);

};

}

#endif // RANDOM_H
