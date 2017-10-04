#include "signalmachine.h"
#include <unistd.h>

SignalMachine::SignalMachine() {}

void SignalMachine::launch() {
    while (1){
        emit requestRefresh();
        sleep(0.2);

    }

}
