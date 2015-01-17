int row[] = {
  9,10,11,12};
int col[] = {
  2,3,4,5,6,8};

int numRows = 4;
int numCols = 6;
int grid[][] = new int[numRows][numCols];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < numRows; i++) {
    pinMode(row[i], OUTPUT);
  }
  for (int i = 0; i < numCols; i++) {
    pinMode(col[i], OUTPUT);
  }
  alloff();
}

void loop() {
  // put your main code here, to run repeatedly: 
  /*for (int i = 0; i < 4; i++) {
   for (int j = 0; j < 3; j++) {
   digitalWrite(row[i], HIGH);
   digitalWrite(col[j], LOW);
   delay(250);
   digitalWrite(col[j], HIGH);
   }
   }*/
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(3, LOW);
  //digitalWrite(4, LOW);
  //digitalWrite(5, LOW);
  //digitalWrite(6, LOW);
  //digitalWrite(8, LOW);
  //digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  //digitalWrite(11, HIGH);
  //digitalWrite(12, HIGH);
  //delay(1000);
  //Serial.print("off");
  //delay(500);
  //alloff();
  //delay(500);
}

void alloff() {
  for (int i = 0; i < numRows; i++) {
    digitalWrite(row[i], LOW);
  }
  for (int j = 0; j < numCols; j++) {
    digitalWrite(col[i], HIGH); 
  }
}


