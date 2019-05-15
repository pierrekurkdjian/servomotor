#include "./servo_sa_hw_adapter/servo_sa_hw_adapter.h"
#include "ocs_core_fwk.h"

using namespace std;
using namespace gmt;

void run() {
    try {
        debug("servo_ctrl_pkg application starts","servoCtrlPkg");

        // create servo_sa_main_ctrl instances
        //servoSaMainCtrl servo_sa_main_ctrl("gmt://servo_dcs/servo_sa_main_ctrl/servo_sa_main_ctrl", "servo_sa_main_ctrl", "127.0.0.1", 10010, "PRIVATE", 100);

        // create servo_sa_hw_adapter instances
        servoSaHwAdapter servo_sa_hw1_adapter("gmt://servo_dcs/servo_sa_hw_adapter/servo_sa_hw1_adapter", "servo_sa_hw1_adapter", "127.0.0.1", 10011, "PRIVATE", 100);

        // create servo_ctrl_app instances

        // create servo_sa_hw_adapter_sim instances

        // create servo_ctrl_sim_app instances

        // start servo_sa_main_ctrl instances
        //servo_sa_main_ctrl.start();


        // start servo_sa_hw_adapter instances
        servo_sa_hw1_adapter.start();

        // start servo_ctrl_app instances

        // start servo_sa_hw_adapter_sim instances

        // start servo_ctrl_sim_app instances

        // wait until components finish
        //servo_sa_main_ctrl.wait();
        servo_sa_hw1_adapter.wait();
    }
    catch(std::runtime_error& e) { error(e.what(),"servoCtrlPkg");            }
    catch(std::exception& e)     { error(e.what(),"servoCtrlPkg");            }
    catch(...)                   { error("unknown exception","servoCtrlPkg"); }
}

int main() {
    run();
    return(0);
}
