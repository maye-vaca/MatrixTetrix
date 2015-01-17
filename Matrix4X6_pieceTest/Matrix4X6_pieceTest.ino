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
  drawPiece(random(1,7));
  //drawPiece(5);
  int x = 0;
  do {
    drawMap();
    x++;
    delay(1);
  } 
  while (x < 100);
  alloff();
  delay(250);
}

void alloff() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      digitalWrite(col[j], HIGH); 
      digitalWrite(row[i], LOW);
      grid[i][j] = 0;
    }
  }
}

void drawMap() {
  //Serial.print("GRID:\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if(grid[i][j] == 1) {
        digitalWrite(row[i], HIGH);
        digitalWrite(col[j], LOW); 
      } 
      else {
        digitalWrite(col[j],HIGH);
      }
    }
    digitalWrite(row[i], LOW);
    for(int j = 0; j < 6; j++) {
      digitalWrite(col[j],HIGH);
    }
    delay(5);
    //Serial.println();
  } 

}

void drawPiece(int num) {
  Serial.println(num);
  if (enoughSpace(num)) {
    switch (num) {
    case 1: 
      for (int i = 1; i < 5; i++) {
        grid[0][i] = 1; 
      }
      break;
    case 2:
      grid[0][2] = grid[0][3] = 1;
      grid[1][2] = grid[1][3] = 1;
      break;
    case 3:
      grid[0][3] = 1;
      grid[1][2] = grid[1][3] = 1;
      grid[2][3] = 1;
      break;
    case 4:
      grid[0][2] = 1;
      grid[1][2] = grid[1][3] = 1;
      grid[2][3] = 1;
      break;
    case 5:
      grid[0][3] = 1;
      grid[1][2] = grid[1][3] = 1;
      grid[2][2] = 1;
      break;
    case 6:
      grid[0][2] = grid[0][3] = grid[0][4] = 1;
      grid[1][4] = 1;
      break;
    case 7:
      grid[0][2] = grid[0][3] = grid[0][4] = 1;
      grid[1][2] = 1;
      break;
    default:
      break;
    }
  }
}

boolean enoughSpace(int num) {
  return true; 
}









