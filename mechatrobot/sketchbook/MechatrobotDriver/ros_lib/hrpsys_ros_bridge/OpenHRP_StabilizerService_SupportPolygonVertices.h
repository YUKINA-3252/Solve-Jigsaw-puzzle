#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_SupportPolygonVertices_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_SupportPolygonVertices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_TwoDimensionVertex.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_SupportPolygonVertices : public ros::Msg
  {
    public:
      uint32_t vertices_length;
      typedef hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex _vertices_type;
      _vertices_type st_vertices;
      _vertices_type * vertices;

    OpenHRP_StabilizerService_SupportPolygonVertices():
      vertices_length(0), vertices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vertices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertices_length);
      if(vertices_lengthT > vertices_length)
        this->vertices = (hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex*)realloc(this->vertices, vertices_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex));
      vertices_length = vertices_lengthT;
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_SupportPolygonVertices"; };
    const char * getMD5(){ return "cf23d460953b52e710154e7238ea2e5b"; };

  };

}
#endif
