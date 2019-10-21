#include <iostream>
#include <cstring>

using namespace std;

class Mobile
{
    public:
        char myNumber_[11];
        void showNumber();
};

class MobileGsm : virtual public Mobile
{
    public:
        int memory_;
        void showMemory();
};

class MobileCdma : virtual public Mobile
{
    public:
        int memory_;
        void showMemory();
};

class MobileCell : public MobileGsm, public MobileCdma
{
    public:
        char OS_[10];
        void showOS();
};

int main()
{
    char number[11];
    int mem1;
    int mem2;
    char os[10];

    cin >> number >> mem1 >> mem2 >> os;

    MobileCell c;
    strcpy(c.myNumber_, number);

    c.MobileGsm::memory_ = mem1;
    c.MobileCdma::memory_ = mem2;

    strcpy(c.OS_, os);

    cout << "The number is ";
    c.showNumber();

    cout << "One memory is ";
    c.MobileGsm::showMemory();

    cout << "The other memory is ";
    c.MobileCdma::showMemory();

    cout << "The os is ";
    c.showOS();

    return 0;
}

void Mobile::showNumber()
{
    cout << myNumber_ << endl;
}

void MobileGsm::showMemory()
{
    cout << memory_ << endl;
}

void MobileCdma::showMemory()
{
    cout << memory_ << endl;
}

void MobileCell::showOS()
{
    cout << OS_ << endl;
}
