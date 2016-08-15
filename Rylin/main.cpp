#include <BearLibTerminal.h>

using namespace std;

int main()
{
    terminal_open();
    terminal_set("window: title='RYLIN'");
    terminal_refresh();
    while(true);
    return 0;
}
