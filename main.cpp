#include "utility.h"

using namespace std;

int main()
{
    listgames Lg;
    listrelation Lr;
    listuser Lu;

    createListgames(Lg);
    createListrelation(Lr);
    createListuser(Lu);

    menu(Lg,Lr,Lu);
    return 0;
}
