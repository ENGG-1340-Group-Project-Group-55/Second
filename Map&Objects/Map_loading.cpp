#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Maps {
private:
    int map_height;
    int map_width;
public:
    Maps(int, int);
    void Map_Loader();
    void Map_Printer();
    char* MapToArray(ifstream&, ifstream&);
    void Location_accessor();
};

/*
int main(){
    Maps Mp(15,30);
    Mp.Map_Loader();
}
*/

Maps::Maps(int a, int b) {
    map_height = a;
    map_width = b;
}


void Maps::Map_Loader() {
    ifstream room_file("/Users/lucas/Documents/GitHub/Initial/Map&Objects/Map_resources/15-15_map.txt");
    if (room_file.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    ifstream object_file("/Users/lucas/Documents/GitHub/Initial/Map&Objects/Object_resources/sofa.txt");
    if (object_file.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    char* hekko = MapToArray(room_file, object_file);
    cout << hekko << endl;
}


char* Maps::MapToArray(ifstream& room_file, ifstream& object_file)
{
    char room_char, object_char;
    int height_tracker = 0;
    int width_tracker = 0;
    char* td_map = new char[map_height * map_width];
        
    while (height_tracker < map_height && room_file >> noskipws >> room_char)
    {
        if (room_char == '\n')
        {
            continue;
        }
   
        if (width_tracker == map_width)
        {
            height_tracker++;
            width_tracker = 0;
        }
        td_map[height_tracker * map_width + width_tracker] = room_char;

        if (height_tracker == object_height && width_tracker == object_width)
        {
            object_file >> noskipws >> object_char;
            td_map[height_tracker * map_width + width_tracker] = object_char;
        }

        width_tracker++;
    }
                           
    for (int i = 0; i < map_height; i++)
    {
        for (int j = 0; j < map_width; j++)
        {
            cout << td_map[i * map_width + j];
        }
        cout << '\n';
    }
    return td_map;
}
