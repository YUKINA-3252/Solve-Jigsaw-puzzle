#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParams_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StepParam.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_StepParams : public ros::Msg
  {
    public:
      uint32_t sps_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParam _sps_type;
      _sps_type st_sps;
      _sps_type * sps;

    OpenHRP_AutoBalancerService_StepParams():
      sps_length(0), sps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sps_length);
      for( uint32_t i = 0; i < sps_length; i++){
      offset += this->sps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t sps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sps_length);
      if(sps_lengthT > sps_length)
        this->sps = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParam*)realloc(this->sps, sps_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParam));
      sps_length = sps_lengthT;
      for( uint32_t i = 0; i < sps_length; i++){
      offset += this->st_sps.deserialize(inbuffer + offset);
        memcpy( &(this->sps[i]), &(this->st_sps), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParam));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StepParams"; };
    const char * getMD5(){ return "4abe0312f4771ffba1e8ca02fe88ee02"; };

  };

}
#endif
