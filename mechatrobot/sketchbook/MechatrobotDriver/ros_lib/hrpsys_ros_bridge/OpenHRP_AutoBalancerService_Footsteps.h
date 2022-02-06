#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footsteps_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footsteps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_Footsteps : public ros::Msg
  {
    public:
      uint32_t fs_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep _fs_type;
      _fs_type st_fs;
      _fs_type * fs;

    OpenHRP_AutoBalancerService_Footsteps():
      fs_length(0), fs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->fs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fs_length);
      for( uint32_t i = 0; i < fs_length; i++){
      offset += this->fs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t fs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fs_length);
      if(fs_lengthT > fs_length)
        this->fs = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->fs, fs_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      fs_length = fs_lengthT;
      for( uint32_t i = 0; i < fs_length; i++){
      offset += this->st_fs.deserialize(inbuffer + offset);
        memcpy( &(this->fs[i]), &(this->st_fs), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps"; };
    const char * getMD5(){ return "f85957b17cc08a30bbfab3dc61b1d556"; };

  };

}
#endif
