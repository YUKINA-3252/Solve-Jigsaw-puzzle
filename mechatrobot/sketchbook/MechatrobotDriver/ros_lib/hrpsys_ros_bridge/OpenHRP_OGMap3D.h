#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_OGMap3D_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_OGMap3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_Point3D.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_OGMap3D : public ros::Msg
  {
    public:
      typedef float _resolution_type;
      _resolution_type resolution;
      typedef hrpsys_ros_bridge::RTC_Point3D _pos_type;
      _pos_type pos;
      typedef int16_t _nx_type;
      _nx_type nx;
      typedef int16_t _ny_type;
      _ny_type ny;
      typedef int16_t _nz_type;
      _nz_type nz;
      uint32_t cells_length;
      typedef uint8_t _cells_type;
      _cells_type st_cells;
      _cells_type * cells;

    OpenHRP_OGMap3D():
      resolution(0),
      pos(),
      nx(0),
      ny(0),
      nz(0),
      cells_length(0), cells(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->resolution);
      offset += this->pos.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_nx;
      u_nx.real = this->nx;
      *(outbuffer + offset + 0) = (u_nx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nx.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nx);
      union {
        int16_t real;
        uint16_t base;
      } u_ny;
      u_ny.real = this->ny;
      *(outbuffer + offset + 0) = (u_ny.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ny.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ny);
      union {
        int16_t real;
        uint16_t base;
      } u_nz;
      u_nz.real = this->nz;
      *(outbuffer + offset + 0) = (u_nz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nz.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nz);
      *(outbuffer + offset + 0) = (this->cells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cells_length);
      for( uint32_t i = 0; i < cells_length; i++){
      *(outbuffer + offset + 0) = (this->cells[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cells[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->resolution));
      offset += this->pos.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_nx;
      u_nx.base = 0;
      u_nx.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nx.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nx = u_nx.real;
      offset += sizeof(this->nx);
      union {
        int16_t real;
        uint16_t base;
      } u_ny;
      u_ny.base = 0;
      u_ny.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ny.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ny = u_ny.real;
      offset += sizeof(this->ny);
      union {
        int16_t real;
        uint16_t base;
      } u_nz;
      u_nz.base = 0;
      u_nz.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nz.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nz = u_nz.real;
      offset += sizeof(this->nz);
      uint32_t cells_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cells_length);
      if(cells_lengthT > cells_length)
        this->cells = (uint8_t*)realloc(this->cells, cells_lengthT * sizeof(uint8_t));
      cells_length = cells_lengthT;
      for( uint32_t i = 0; i < cells_length; i++){
      this->st_cells =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cells);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_OGMap3D"; };
    const char * getMD5(){ return "41db76e604ab520cf21a65c1085e2476"; };

  };

}
#endif
