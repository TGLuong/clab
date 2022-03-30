#ifndef DATA_H
#define DATA_H

class Data {
    private:
        int x;
    public:
        Data(int x): x(x) {  };
        int get() {
            return x;
        }
};

#endif
