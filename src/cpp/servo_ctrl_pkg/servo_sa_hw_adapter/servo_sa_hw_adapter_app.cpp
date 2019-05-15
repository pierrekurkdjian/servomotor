#include "servo_sa_hw_adapter.h"

using namespace std;
using namespace gmt;

void run() {
    try {
        debug("servo_sa_hw_adapter application starts","servoSaHwAdapter");

        // create instances
        servoSaHwAdapter servo_sa_hw1_adapter("gmt://servo_dcs/servo_sa_hw_adapter/servo_sa_hw1_adapter", "servo_sa_hw1_adapter", "127.0.0.1", 10011, "PRIVATE", 100);

        // start instances
        servo_sa_hw1_adapter.start();

        // wait until components finish
        servo_sa_hw1_adapter.wait();
    }
    catch(std::runtime_error& e) { error(e.what(),"servoSaHwAdapter");            }
    catch(std::exception& e)     { error(e.what(),"servoSaHwAdapter");            }
    catch(...)                   { error("unknown exception","servoSaHwAdapter"); }
}

int main() {
    run();
    return(0);
}
