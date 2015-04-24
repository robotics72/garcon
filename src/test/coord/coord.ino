// 123.ino

int colDetectedBeacons;

typedef struct TDetectedBeacon{
	int id;
	int angle;
};
typedef struct TBeacon{
	int id;
	int x;
	int y;
};
const int colBeacons=2; 	// количество маяков в базе (dbBeacons)
struct TDetectedBeacon beacons[100];


TBeacon dbBeacons[] = {
	{ 1,  0, 0}, 
	{ 2, 20, 0},
};





void setup() {
    Serial.begin(9600);

	beacons[0].id = 1;
	beacons[0].angle =330;

	beacons[1].id = 2;
	beacons[1].angle = 30;

	CalcXY(0, 1);

/*
for(int i=0; i<5; i++){
  Serial.print(beacons[i].id);
  Serial.print(" ");
  Serial.println(beacons[i].angle);
  }   
  */
}


void loop() {

  }
  


void CalcXY(int i1,int i2){
  float _x;
  float _y;
  float k1;
  float k2;
  int id1;
  int id2;
  float x1;
  float y1;
  float x2;
  float y2;
  k1=tan(beacons[i1].angle*3.14/180);
  k2=tan(beacons[i2].angle*3.14/180);
  id1 = beacons[i1].id;
  id2 = beacons[i2].id;
  for(int i=0; i<colBeacons; i++){
     if (dbBeacons[i].id == id1){
     	x1 = dbBeacons[i].x;
     	y1 = dbBeacons[i].y;     	
     }
     if (dbBeacons[i].id == id2){
     	x2 = dbBeacons[i].x;
     	y2 = dbBeacons[i].y;     	
     }
   }
   _x = (y2 - y1 + k1 * x1 - k2 * x2) / (k1 - k2);
   _y = k1 * (_x - x1) + y1;
   Serial.println(_x);
   Serial.println(_y);
  }


  