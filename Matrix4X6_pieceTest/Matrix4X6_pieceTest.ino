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
  drawPiece(1);
}

void loop() {
  // put your main code here, to run repeatedly: 
  drawPiece(random(1,4));
  alloff();
}

void alloff() {
  for (int i = 0; i < numRows; i++) {
    digitalWrite(row[i], LOW);
  }
  for (int j = 0; j < numCols; j++) {
    digitalWrite(col[i], HIGH); 
  }
}

void drawMap() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if(grid[i][j]) {
        digitalWrite(row[i], LOW);
        digitalWrite(col[i], HIGH); 
      }
      delay(100);
      alloff();
    }
  } 

}

void drawPiece(int num) {
  if (enoughSpace(num)) {
    switch (num) {
      case (1): 
        for (int i = 0; i < 4; i++) {
          grid[1][i] = 1; 
        }
        break;
     case(2):
       grid[0][2] = grid[0][3] = grid[1][2] = grid[1][3] = 1;
       
}

boolean enoughSpace(int num) {
   return true; 
}



