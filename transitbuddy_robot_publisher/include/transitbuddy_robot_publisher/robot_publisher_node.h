/*
* Copyright (C) 2013.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ROBOT_PUBLISHER_NODE_H
#define ROBOT_PUBLISHER_NODE_H

#include "ros/ros.h"
#include <gazebo_msgs/ModelStates.h>
#include <geometry_msgs/Pose.h>
#include <transitbuddy_msgs/PoseWithIDArray.h>
#include <transitbuddy_robot_publisher/robot_publisher_defaults.h>

class RobotPublisherNode {
        
        public:
                RobotPublisherNode(ros::NodeHandle & n);
                ~RobotPublisherNode();
                void callbackHumanPose(const transitbuddy_msgs::PoseWithIDArray::ConstPtr& msg);
                void callbackGazeboModel(const gazebo_msgs::ModelStates::ConstPtr& msg);
                double frequency() {
                        return frequency_;
                }
                void publishRobotPose();
        private:
                ros::NodeHandle n_;
                ros::NodeHandle n_param_;
                double frequency_;
                bool publish_;
                std::string frame_id_;
                ros::Subscriber sub_;
                ros::Subscriber subGazebo_;
                ros::Publisher pub_;
                transitbuddy_msgs::PoseWithIDArray robotPoses_;
                geometry_msgs::Pose offset_map_;
                  

};

#endif //ROBOT_PUBLISHER_NODE_H

