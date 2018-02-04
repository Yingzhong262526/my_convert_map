#ifndef WRITESMAP_ZHAOYINGZHONG_20180201_H
#define WRITESMAP_ZHAOYINGZHONG_20180201_H



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "map.pb.h"

using namespace std;


class Message_AdvancedArea;
class Message_AdvancedCurve;
class Message_AdvancedLine;
class Message_AdvancedPoint;
class Message_Device;
class Message_LaserDevice;
class Message_Map;
class Message_MapAttribute;
class Message_MapHeader;
class Message_MapLine;
class Message_MapPos;
class Message_MapProperty;
class Message_PatrolRoute;
class Message_PatrolRouteStation;

//data define
struct MapPos
{
    double x;
    double y;
};

struct MapHeader
{
    string map_type;
    string map_name;
    MapPos min_pos;
    MapPos max_pos;
    double resolution;
    string version;
};

struct MapProperty
{
   string key;
   string type;
   string value;
//   enum oneof_value
//   {
//       STRING =1 ,
//       BOOL =2 ,
//       INT32 = 3 ,
//       UINT32 = 4 ,
//       INT64  = 5 ,
//       UINT64 = 6 ,
//       fLOAT = 7 ,
//       DOUBLE = 8 ,
//       BYTE  =9
//   };
};

struct MapAttribute
{
      string description;
      int color_pen;
      int color_brush;
      int color_font;
};

struct Device
{
    int id;
    MapPos laser_margin_pos;
};

struct MapLine
{
    MapPos start_pos;
    MapPos  end_pos;
};

struct AdvancedPoint
{
     string class_name;
     string instance_name;
     MapPos pos;
     double dir;
     MapProperty property;
     MapAttribute attribute;
};

struct AdvancedLine
{
    string class_name;
    string instance_name;
    MapLine line;
    MapProperty property;
    MapAttribute attribute;
};

struct  AdvancedCurve
{
    string class_name;
    string instance_name;
    AdvancedPoint start_pos;
    AdvancedPoint end_pos;
    MapPos control_pos1;
    MapPos control_pos2;
    MapProperty property;
    Device devices;
    MapAttribute attribute;
};

struct AdvancedArea
{
    string class_name;
    string instance_name;
    MapPos pos_group[4];
    double dir;
    MapProperty property;
    Device devices;
    MapAttribute attribute;
};

struct PatrolRouteStation
{
    string id;
};

struct PatrolRoute
{
    string name;
    PatrolRouteStation station_list[32];
    double max_acc;
    double max_speed;
    double max_rot;
    double max_rot_acc;
};


class WriteSmap{

 public:
    WriteSmap();
    ~WriteSmap();
    void PromptMapPos(vector<MapPos>& normal_pos);
    void PromptMapLine(vector<MapLine>& normal_line);
    void PromptAdvancdePoint(vector<AdvancedPoint>& advance_point);
    void PromptAdvanceLine(vector<AdvancedLine>& advance_line);
    void PromptAdvanceCurve(vector<AdvancedCurve>& advance_curve);
    void PromptAdvanceArea(vector<AdvancedArea>& advance_area);
    void PromptPatrolRounte(vector<PatrolRoute>& patrol_route);

  public:
     Message_Map map_;
     string mapDirectory_;
     MapHeader m_header;
     vector<MapPos> m_normal_pos_list;
     vector<MapLine> m_normal_line_list;
     vector<AdvancedPoint> m_advance_point_list;
     vector<AdvancedLine> m_advance_line_list;
     vector<AdvancedCurve> m_advance_curve_list;
     vector<AdvancedArea> m_advance_area_list;
     vector<PatrolRoute> m_patrol_route_list;

};

#endif
