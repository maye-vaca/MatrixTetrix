int row[] = {
  12,11,10,9};
int col[] = {
  8,7,6,5,4,3};

int numRows = 4;
int numCols = 6;
int grid[4][6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < numRows; i++) {
    pinMode(row[i], OUTPUT);
  }
  for (int i = 0; i < numCols; i++) {
    pinMode(col[i], OUTPUT);
  }
  drawPiece(2);
  alloff();
}

void loop() {
  // put your main code here, to run repeatedly: 
  //drawPiece(random(1,2));
  
  drawMap();
  //delay(500);
  //alloff();
  //delay(500);
}

void alloff() {
  for (int i = 0; i < numRows; i++) {
    digitalWrite(row[i], LOW);
  }
  for (int j = 0; j < numCols; j++) {
    digitalWrite(col[j], HIGH); 
  }
}

void drawMap() {
  alloff();
  Serial.print("GRID:\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if(grid[i][j]) {
        digitalWrite(row[i], HIGH);
        digitalWrite(col[i], LOW); 
      }
      
      Serial.print(grid[i][j] + " ");
      delay(100);
    }
    Serial.println();
  } 

}

void drawPiece(int num) {
  Serial.println(num);
  if (enoughSpace(num)) {
    switch (num) {
      case 1: 
        for (int i = 0; i < 4; i++) {
          grid[1][i] = 1; 
        }
        break;
     case 2:
       grid[0][2] = grid[0][3] = grid[1][2] = grid[1][3] = 1;
       break;
     default:
       break;
    }
  }
}

boolean enoughSpace(int num) {
   return true; 
}



