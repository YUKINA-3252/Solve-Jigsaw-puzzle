#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_setCollisionLoop_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_setCollisionLoop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_SETCOLLISIONLOOP[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_setCollisionLoop";

  class OpenHRP_CollisionDetectorService_setCollisionLoopRequest : public ros::Msg
  {
    public:
      typedef int16_t _loop_type;
      _loop_type loop;

    OpenHRP_CollisionDetectorService_setCollisionLoopRequest():
      loop(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loop.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->loop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loop.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETCOLLISIONLOOP; };
    const char * getMD5(){ return "20fd1dd4b0247b9aecaa4bdf59bf1866"; };

  };

  class OpenHRP_CollisionDetectorService_setCollisionLoopResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_CollisionDetectorService_setCollisionLoopResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETCOLLISIONLOOP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_CollisionDetectorService_setCollisionLoop {
    public:
    typedef OpenHRP_CollisionDetectorService_setCollisionLoopRequest Request;
    typedef OpenHRP_CollisionDetectorService_setCollisionLoopResponse Response;
  };

}
#endif
