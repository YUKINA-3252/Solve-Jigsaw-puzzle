#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_TorqueControllerService_torqueControllerParam : public ros::Msg
  {
    public:
      typedef float _tc_type;
      _tc_type tc;
      typedef float _ke_type;
      _ke_type ke;
      typedef float _kd_type;
      _kd_type kd;
      typedef float _ki_type;
      _ki_type ki;
      typedef float _alpha_type;
      _alpha_type alpha;
      typedef float _beta_type;
      _beta_type beta;

    OpenHRP_TorqueControllerService_torqueControllerParam():
      tc(0),
      ke(0),
      kd(0),
      ki(0),
      alpha(0),
      beta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->tc);
      offset += serializeAvrFloat64(outbuffer + offset, this->ke);
      offset += serializeAvrFloat64(outbuffer + offset, this->kd);
      offset += serializeAvrFloat64(outbuffer + offset, this->ki);
      offset += serializeAvrFloat64(outbuffer + offset, this->alpha);
      offset += serializeAvrFloat64(outbuffer + offset, this->beta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ke));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kd));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ki));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->alpha));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beta));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_torqueControllerParam"; };
    const char * getMD5(){ return "418bfbbaca8a066928344703def43b7f"; };

  };

}
#endif
