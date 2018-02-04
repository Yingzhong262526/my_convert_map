#include "write_smap.h"

WriteSmap::WriteSmap()
{

}

WriteSmap::~WriteSmap()
{

}


void WriteSmap::PromptMapPos(vector<MapPos>& normal_pos)
{
   for(int i=0;i<normal_pos.size();++i)
   {
       Message_MapPos* mapPos = map_.add_normal_pos_list();
       mapPos->set_x(normal_pos[i].x);
       mapPos->set_y(normal_pos[i].y);
   }
}

void WriteSmap::PromptMapLine(vector<MapLine>& normal_line)
{
    for(int i=0;i<normal_line.size();++i)
    {
        Message_MapLine* mapLine = map_.add_normal_line_list();
        Message_MapPos* lineStartPos = new Message_MapPos;
        lineStartPos->set_x(normal_line[i].start_pos.x);
        lineStartPos->set_y(normal_line[i].start_pos.y);
        mapLine->set_allocated_start_pos(lineStartPos);
        Message_MapPos* lineEndPos = new Message_MapPos;
        lineEndPos->set_x(normal_line[i].end_pos.x);
        lineEndPos->set_y(normal_line[i].end_pos.y);
        mapLine->set_allocated_end_pos(lineEndPos);
    }
}

void WriteSmap::PromptAdvancdePoint(vector<AdvancedPoint>& advance_point)
{
    for(int i=0;i<advance_point.size();++i)
    {
        Message_AdvancedPoint* advancePoint = map_.add_advanced_point_list();
        advancePoint->set_class_name(advance_point[i].class_name);
        advancePoint->set_instance_name(advance_point[i].instance_name);
        Message_MapPos* advancePointPos = new Message_MapPos;
        advancePointPos->set_x(advance_point[i].pos.x);
        advancePointPos->set_y(advance_point[i].pos.y);
        advancePoint->set_allocated_pos(advancePointPos);
        advancePoint->set_dir(advance_point[i].dir);
        if(advancePoint->has_attribute())
         {
          Message_MapAttribute* attribute = new Message_MapAttribute;
          attribute->set_description(advance_point[i].attribute.description);
          attribute->set_color_pen(advance_point[i].attribute.color_pen);
          attribute->set_color_brush(advance_point[i].attribute.color_brush);
          attribute->set_color_font(advance_point[i].attribute.color_font);
          advancePoint->set_allocated_attribute(attribute);
         }
        else
          {

        }

    }
}

void WriteSmap::PromptAdvanceLine(vector<AdvancedLine>& advance_line)
{
   for(int i=0;i<advance_line.size();++i)
   {
       Message_AdvancedLine* advanceLine = map_.add_advanced_line_list();
       advanceLine->set_class_name(advance_line[i].class_name);
       advanceLine->set_instance_name(advance_line[i].instance_name);
       if(advanceLine->has_line())
       {
          Message_MapLine* line =new Message_MapLine;
          Message_MapPos* startPos = new Message_MapPos;
          startPos->set_x(advance_line[i].line.start_pos.x);
          startPos->set_y(advance_line[i].line.start_pos.y);
          line->set_allocated_start_pos(startPos);
          Message_MapPos* endPos;
          endPos->set_x(advance_line[i].line.end_pos.x);
          endPos->set_y(advance_line[i].line.end_pos.y);
          line->set_allocated_end_pos(endPos);
          advanceLine->set_allocated_line(line);
       }
       else
       {

       }
       if(advanceLine->has_attribute())
       {
           Message_MapAttribute* attribute = new Message_MapAttribute;
           attribute->set_description(advance_line[i].attribute.description);
           attribute->set_color_pen(advance_line[i].attribute.color_pen);
           attribute->set_color_brush(advance_line[i].attribute.color_brush);
           attribute->set_color_font(advance_line[i].attribute.color_font);
           advanceLine->set_allocated_attribute(attribute);
       }
       else
       {

       }
   }
}
void WriteSmap::PromptAdvanceCurve(vector<AdvancedCurve>& advance_curve)
{
    for(int i=0;i<advance_curve.size();++i)
    {
        Message_AdvancedCurve* advanceCurve =map_.add_advanced_curve_list();
        advanceCurve->set_class_name(advance_curve[i].class_name);
        advanceCurve->set_instance_name(advance_curve[i].instance_name);

        Message_AdvancedPoint* startPoint = new Message_AdvancedPoint;
        startPoint->set_class_name(advance_curve[i].start_pos.class_name);
        startPoint->set_instance_name(advance_curve[i].start_pos.instance_name);
        if(startPoint->has_pos())
        {
        Message_MapPos* pos = new Message_MapPos;
        pos->set_x(advance_curve[i].start_pos.pos.x);
        pos->set_y(advance_curve[i].start_pos.pos.y);
        startPoint->set_allocated_pos(pos);
        }
        else
        {

        }

        startPoint->set_dir(advance_curve[i].start_pos.dir);
        if(startPoint->has_attribute())
        {
         Message_MapAttribute* attr;
         attr->set_description(advance_curve[i].start_pos.attribute.description);
         attr->set_color_pen(advance_curve[i].start_pos.attribute.color_pen);
         attr->set_color_brush(advance_curve[i].start_pos.attribute.color_brush);
         attr->set_color_font(advance_curve[i].start_pos.attribute.color_font);
         startPoint->set_allocated_attribute(attr);
        }
        else
        {

        }
        Message_MapProperty* prop=startPoint->add_property();
        prop->set_key(advance_curve[i].start_pos.property.key);
        prop->set_type(advance_curve[i].start_pos.property.type);
        prop->set_value(advance_curve[i].start_pos.property.value);
#if 0
        if(prop->has_string_value())
        {
            prop->set_string_value();
        }
        if(prop->has_bool_value())
        {
            prop->set_bool_value();
        }
        if(prop->has_int32_value())
        {
            prop->set_int32_value();
        }
        if(prop->has_uint32_value())
        {
            prop->set_uint32_value();
        }
        if(prop->has_int64_value())
        {
            prop->set_int64_value();
        }
        if(prop->has_uint64_value())
        {
            prop->set_uint64_value();
        }
        if(prop->has_float_value())
        {
            prop->set_float_value();
        }
        if(prop->has_double_value())
        {
            prop->set_double_value();
        }
        if(prop->has_bytes_value())
        {
            prop->set_bytes_value();
        }
#endif
        advanceCurve->set_allocated_start_pos(startPoint);

         Message_AdvancedPoint* endPoint = new Message_AdvancedPoint;
         endPoint->set_class_name(advance_curve[i].end_pos.class_name);
         endPoint->set_instance_name(advance_curve[i].end_pos.instance_name);
         if(endPoint->has_pos())
         {
         Message_MapPos* endPos = new Message_MapPos;
         endPos->set_x(advance_curve[i].end_pos.pos.x);
         endPos->set_y(advance_curve[i].end_pos.pos.y);
         endPoint->set_allocated_pos(endPos);
         }
         else
         {

         }

         endPoint->set_dir(advance_curve[i].end_pos.dir);
         if(endPoint->has_attribute())
         {
          Message_MapAttribute* endPointAttr = new Message_MapAttribute;
          endPointAttr->set_description(advance_curve[i].end_pos.attribute.description);
          endPointAttr->set_color_pen(advance_curve[i].end_pos.attribute.color_pen);
          endPointAttr->set_color_brush(advance_curve[i].end_pos.attribute.color_brush);
          endPointAttr->set_color_font(advance_curve[i].end_pos.attribute.color_font);
          endPoint->set_allocated_attribute(endPointAttr);
         }
         else
         {

         }
         Message_MapProperty* endPointProp=endPoint->add_property();
         endPointProp->set_key(advance_curve[i].end_pos.property.key);
         endPointProp->set_type(advance_curve[i].end_pos.property.type);
         endPointProp->set_value(advance_curve[i].end_pos.property.value);
         advanceCurve->set_allocated_end_pos(endPoint);

          if(advanceCurve->has_control_pos1())
          {
              Message_MapPos* control_pos1 = new Message_MapPos;
              control_pos1->set_x(advance_curve[i].control_pos1.x);
              control_pos1->set_y(advance_curve[i].control_pos1.y);
              advanceCurve->set_allocated_control_pos1(control_pos1);
          }
          else
          {

          }
           if(advanceCurve->has_control_pos2())
           {
               Message_MapPos* control_pos2 = new Message_MapPos;
               control_pos2->set_x(advance_curve[i].control_pos2.x);
               control_pos2->set_y(advance_curve[i].control_pos2.y);
               advanceCurve->set_allocated_control_pos1(control_pos2);
           }
           else
           {

           }
/*
           Message_MapProperty* advanceCurveProperty = advanceCurve.add_property();
           advanceCurveProperty->set_key(advance_curve.property.key);
           advanceCurveProperty->set_type(advance_curve.property.type);
           advanceCurveProperty->set_value(advance_curve.property.value);
*/
           Message_Device* advanceCurveDevice = advanceCurve->add_devices();
      //     advanceCurveDevice->set_model_name();
    }
}

void WriteSmap::PromptAdvanceArea(vector<AdvancedArea>& advance_area)
{

}
void WriteSmap::PromptPatrolRounte(vector<PatrolRoute>& patrol_route)
{

}
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " SMAP_FILE" << endl;
    return -1;
  }

  //tutorial::AddressBook address_book;
   WriteSmap smap;

   smap.mapDirectory_ = "D:/map/402.smap";
   smap.m_header.map_name = "402.smap" ;
   smap.m_header.map_type = "2D-map" ;
   smap.m_header.max_pos.x = 166.000;
   smap.m_header.max_pos.y = 86.600;
   smap.m_header.min_pos.x = -43.800;
   smap.m_header.min_pos.y = -70.200;
   smap.m_header.resolution = 0.02;
   smap.m_header.version = "1.0.0" ;

   MapPos pos;
   pos.x = -43.80;
   pos.y = -20.80;
   smap.m_normal_pos_list.push_back(pos);
   pos.x = -43.60 ;
   pos.y = -20.60 ;
   smap.m_normal_pos_list.push_back(pos);
   pos.x = -43.40 ;
   pos.y = -20.40 ;
   smap.m_normal_pos_list.push_back(pos);
   pos.x = -43.20 ;
   pos.y = -20.00 ;
   smap.m_normal_pos_list.push_back(pos);

   MapLine line;
   line.start_pos.x = 59.280;
   line.start_pos.y = -24.420;
   line.end_pos.x = 63.270 ;
   line.end_pos.y = -22.280 ;
   smap.m_normal_line_list.push_back(line);
   line.start_pos.x =116.540;
   line.start_pos.y = -52.120;
   line.end_pos.x = 145.040;
   line.end_pos.y = -51.880;
   smap.m_normal_line_list.push_back(line);


   AdvancedPoint advance_point;
   advance_point.class_name= "LandMark";
   advance_point.instance_name = "0";
   advance_point.pos.x = 18.420;
   advance_point.pos.y = 9.270;
   smap.m_advance_point_list.push_back(advance_point);
   advance_point.class_name= "RobotHome";
   advance_point.instance_name = "1";
   advance_point.pos.x = 21.930;
   advance_point.pos.y = 29.520;
   smap.m_advance_point_list.push_back(advance_point);
   advance_point.class_name= "LandMark";
   advance_point.instance_name = "2";
   advance_point.pos.x = 22.415;
   advance_point.pos.y = 38.103;
   advance_point.property.key = "spin";
   advance_point.property.type = "int32";
   advance_point.property.value = "MQ==" ;
   smap.m_advance_point_list.push_back(advance_point);

   AdvancedLine advance_line;
   advance_line.class_name ="ForbiddenLine" ;
   advance_line.instance_name = "0";
   advance_line.line.start_pos.x= 50.970;
   advance_line.line.start_pos.y = 28.460 ;
   advance_line.line.end_pos.x = 74.690 ;
   advance_line.line.end_pos.y = 28.460 ;
   smap.m_advance_line_list.push_back(advance_line);
   advance_line.class_name ="ForbiddenLine" ;
   advance_line.instance_name = "1";
   advance_line.line.start_pos.x= -18.460;
   advance_line.line.start_pos.y = 14.010;
   advance_line.line.end_pos.x = 3.280 ;
   advance_line.line.end_pos.y = 14.010 ;
   smap.m_advance_line_list.push_back(advance_line);
   advance_line.class_name ="VirtualLine" ;
   advance_line.instance_name = "2";
   advance_line.line.start_pos.x= 45.600;
   advance_line.line.start_pos.y = -2.580;
   advance_line.line.end_pos.x = 111.70;
   advance_line.line.end_pos.y = -2.580;
   smap.m_advance_line_list.push_back(advance_line);
   advance_line.class_name ="VirtualLine" ;
   advance_line.instance_name = "3";
   advance_line.line.start_pos.x= 4597;
   advance_line.line.start_pos.y = -1440;
   advance_line.line.end_pos.x = 10725;
   advance_line.line.end_pos.y = -1440;
   smap.m_advance_line_list.push_back(advance_line);

   AdvancedCurve advance_curve;
   advance_curve.class_name = "BezierPath";
   advance_curve.start_pos.class_name ="LandMark" ;
   advance_curve.start_pos.instance_name = "0" ;
   advance_curve.start_pos.pos.x = 18.420;
   advance_curve.start_pos.pos.y = 9.270;
   advance_curve.end_pos.class_name = "LandMark" ;
   advance_curve.end_pos.instance_name = "1" ;
   advance_curve.end_pos.pos.x= 21.930;
   advance_curve.end_pos.pos.y = 29.520 ;
   advance_curve.control_pos1.x = 22.009 ;
   advance_curve.control_pos1.y = 28.664 ;
   advance_curve.control_pos2.x = 22.369 ;
   advance_curve.control_pos2.y = 20.501 ;
   smap.m_advance_curve_list.push_back(advance_curve);
   advance_curve.class_name = "BezierPath";
   advance_curve.start_pos.class_name ="LandMark" ;
   advance_curve.start_pos.instance_name = "1" ;
   advance_curve.start_pos.pos.x = 21.930;
   advance_curve.start_pos.pos.y = 29.520;
   advance_curve.end_pos.class_name = "LandMark" ;
   advance_curve.end_pos.instance_name = "2" ;
   advance_curve.end_pos.pos.x= 22.415;
   advance_curve.end_pos.pos.y = 38.103;
   advance_curve.control_pos1.x = -32.702;
   advance_curve.control_pos1.y = 6.313 ;
   advance_curve.control_pos2.x = -32.702 ;
   advance_curve.control_pos2.y = 6.313 ;
   smap.m_advance_curve_list.push_back(advance_curve);

   AdvancedArea advance_area;
   advance_area.class_name = "AdvanceArea";
   advance_area.instance_name = "1";
   advance_area.pos_group[0].x = 1.889 ;
   advance_area.pos_group[0].y = 2.250 ;
   advance_area.pos_group[1].x = 2.380 ;
   advance_area.pos_group[1].y = 2.250 ;
   advance_area.pos_group[2].x = 2.380 ;
   advance_area.pos_group[2].y = 1.751 ;
   advance_area.pos_group[3].x = 1.889 ;
   advance_area.pos_group[3].y = 1.751 ;
   advance_area.property.key = "ultrasonic" ;
   advance_area.property.type = "bool" ;
   advance_area.property.value = "ZmFsc2U" ;
   advance_area.property.key ="fallingdown" ;
   advance_area.property.type = "bool" ;
   advance_area.property.value = "ZmFsc2U=" ;
   smap.m_advance_area_list.push_back(advance_area);

   PatrolRoute patrol_route;
   patrol_route.name = "route1";
   patrol_route.station_list[0].id = "LM1" ;
   patrol_route.station_list[0].id = "LM2" ;
   patrol_route.max_acc = 1.5;
   patrol_route.max_speed = 0.5 ;
   patrol_route.max_rot = 1.0 ;
   patrol_route.max_rot_acc = 0.5;
   smap.m_patrol_route_list.push_back(patrol_route);

   //FCad fcad_;
  {
   fstream input(argv[1], ios::in | ios::binary);
   if (!input)
    {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    }
   else if (!smap.map_.ParseFromIstream(&input))
    {
      cerr << "Failed to parse smap file" << endl;
      return -1;
    }
  }

   smap.map_.set_map_directory(smap.mapDirectory_);
   Message_MapHeader* map_header = new Message_MapHeader;
   map_header->set_map_type(smap.m_header.map_type);
   map_header->set_map_name(smap.m_header.map_name);
   if(map_header->has_min_pos())
   {
       Message_MapPos* minPos = new Message_MapPos;
       minPos->set_x(smap.m_header.min_pos.x);
       minPos->set_y(smap.m_header.min_pos.y);
       map_header->set_allocated_min_pos(minPos);
   }
   if(map_header->has_max_pos())
   {
       Message_MapPos* maxPos = new Message_MapPos;
       maxPos->set_x(smap.m_header.max_pos.x);
       maxPos->set_y(smap.m_header.max_pos.y);
       map_header->set_allocated_max_pos(maxPos);
   }
   map_header->set_resolution(smap.m_header.resolution);
   map_header->set_version(smap.m_header.version);
   smap.map_.set_allocated_header(map_header);

   smap.PromptMapPos(smap.m_normal_pos_list);
   smap.PromptMapLine(smap.m_normal_line_list);
   smap.PromptAdvancdePoint(smap.m_advance_point_list);
   smap.PromptAdvanceLine(smap.m_advance_line_list);
   smap.PromptAdvanceCurve(smap.m_advance_curve_list);
 //  smap.PromptAdvanceArea(smap.m_advance_area_list);
 //  smap.PromptPatrolRounte(smap.m_patrol_route_list);

 {
   fstream output(argv[1], ios::out | ios::trunc | ios::binary);
   if (!smap.map_.SerializeToOstream(&output))
    {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
 }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}

