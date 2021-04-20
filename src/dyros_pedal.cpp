#include "../include/dyros_pedal/dyros_pedal.h"

DyrosPedal::DyrosPedal()
{
    walking_cmd_pub_ = nh_.advertise<dyros_pedal::WalkingCommand>("/tocabi/pedalcommand", 100);
    pedal_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &DyrosPedal::pedalCallback, this);
    
}

void DyrosPedal::pedalCallback(const sensor_msgs::Joy::ConstPtr& pedal)
{
//    if (pedal->axes[1] > 0.5)
//    {
//        walk_cmd_ = true;
//        walk_cmd_msg_.x = 1.0;
//    }
//    else
//    {
//        walk_cmd_ = false;
//        walk_cmd_msg_.x = 0.0;
//    }
    // if(pedal->buttons[8] == 1.0){
    //     walk_cmd_ = true;
    // }
    // if(pedal->buttons[6] == 1.0){
    //     walk_cmd_ =false;
    // }

    // walk_cmd_msg_.x = pedal->axes[1];
    // walk_cmd_msg_.y = pedal->axes[3];
    // walk_cmd_msg_.z = pedal->axes[2]; //default is 1.0, when the button pushed, -1.0
    // std::cout << pedal->axes[3] << std::endl;
    // walk_cmd_msg_.walk_mode = walk_cmd_;
    // walk_cmd_msg_.height = 0.0;
    // walk_cmd_msg_.height = pedal->axes[0];
    // walk_cmd_msg_.theta = pedal->axes[4];
    // walk_cmd_msg_.step_length_x = pedal->buttons[1];
    // walk_cmd_msg_.step_length_y = pedal->buttons[2];
    // std::cout << "B" <<walk_cmd_msg_.theta << "X" <<pedal->axes[4] << std::endl;

    walk_cmd_msg_.step_length_x = pedal->axes[0];
    walk_cmd_msg_.z = pedal->axes[1];
    walk_cmd_msg_.theta = pedal->axes[2];


    // if (walk_cmd_ ==true)
    walking_cmd_pub_.publish(walk_cmd_msg_);
    // std::cout << "step_length : " << walk_cmd_msg_.step_length_x << std::endl;
    // std::cout << "trigger(z) : " << walk_cmd_msg_.z << std::endl;
    // std::cout << "theta : " << walk_cmd_msg_.theta << std::endl << std::endl;

}




int main(int argc, char** argv)
{
    std::cout << "Pedal Started"<<std::endl;
    ros::init(argc, argv, "dyros_pedal");
    DyrosPedal dyrospedal;
    std::cout << "Pedal Controller Started"<<std::endl;
    while(ros::ok())
    {
        ros::spinOnce();
    }
}
