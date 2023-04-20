 /*
 * File: main.c
 * Author: Nguyễn Tuấn Đạt
 * Date: 20/04/2023
 * Description:  i2c master transmit 
 */


 // Define the SDA and SCL pins
#define SDA_PIN A4
#define SCL_PIN A3
// Define macros to set the SDA and SCL pins high and low
#define SDA_HIGH digitalWrite(SDA_PIN, HIGH);
#define SDA_LOW digitalWrite(SDA_PIN, LOW);
#define SCL_HIGH digitalWrite(SCL_PIN, HIGH);
#define SCL_LOW digitalWrite(SCL_PIN, LOW);



/*
*Function: i2c_StartCondition
*Description: Start the I2C communication by sending a start condition
*Input:
*     none
*Output:
*     none
*/
void i2c_StartCondition()
{
  // Set the SDA and SCL pins high
  SDA_HIGH;
  SCL_HIGH;
  // Set the SDA and SCL pins to output mode
  pinMode(SDA_PIN,OUTPUT);
  pinMode(SCL_PIN,OUTPUT);
  delayMicroseconds(50);
  SDA_LOW;
  delayMicroseconds(25);
  SCL_LOW;
}
/*
*Function: i2c_SendByte
*Description: Send a byte of data over I2C
*Input:
*     Data - i2c_SendByte
*Output:
*     none
*/
void i2c_SendByte(uint8_t Data)
{
  uint8_t i;
  for(i = 0; i < 8 ; i++)
  {
    // Check if the current bit is high or low and set the SDA pin accordingly
    if((Data & 0x80) != 0)
    {
      SDA_HIGH;
    }else
    {SDA_LOW;
    }
      // Shift the data byte to the left by one bit    
    Data = Data <<1;
    SCL_HIGH;
    delayMicroseconds(25);
    SCL_LOW;
    delayMicroseconds(25);

  }
}
/*
*Function: i2c_ReadAck
*Description: Read an acknowledgement from the slave device
*Input:
*     none
*Output:
*     none
*/
uint8_t i2c_ReadAck(void)
{
  uint8_t ack;
  pinMode(SDA_PIN, INPUT);
  SCL_HIGH;
  delayMicroseconds(25);
  ack = digitalRead(SDA_PIN);
  SCL_LOW;
  pinMode(SDA_PIN, OUTPUT); 
  return ack;
}
/*
*Function: i2c_StopCondition
*Description: End the I2C communication by sending a stop condition
*Input:
*     none
*Output:
*     none
*/
void i2c_StopCondition()
{
  delayMicroseconds(25);
  SDA_LOW;
  delayMicroseconds(25);
  SCL_HIGH;
  delayMicroseconds(25);
  SDA_HIGH;
}
/*
*Function: i2c_MasterTransmit
*Description: Send data to the slave device
*Input:
*     address - uint8_t
*     *pData - char
*Output:
*     return 1
*/
uint8_t i2c_MasterTransmit(uint8_t address, char *pData)
{
    uint8_t ACK;
    // Send a start condition to begin the I2C communication
    i2c_StartCondition();
     // Shift the address left by one bit to make room for the write bit
    address = address << 1;
    // Send the address over I2C
    i2c_SendByte(address);
    // Read the acknowledgement from the slave device
    ACK = i2c_ReadAck();
    // If the slave device does not acknowledge, stop communication and return an error code (-1)
    if(ACK  == 1)
    {
      i2c_StopCondition();
      return -1;
    }
    // Loop through each character in the data string
    while(*pData != '\0')
    {
      
    i2c_SendByte(*pData );
    ACK = i2c_ReadAck();
          if(ACK  == 1)
            {
            i2c_StopCondition();
            return -1;
            }
    pData ++;

    }
    // Send the null character to indicate the end of the data string
    i2c_SendByte('\0'); 
    // If the slave device does not acknowledge, stop communication and return an error code (-1)
    ACK = i2c_ReadAck();
    if (ACK == 1)
    {
        i2c_StopCondition();
        return -1;
    }
    // Send a stop condition to end the I2C communication
    i2c_StopCondition();
    return 1;
}
void setup()
{
  delay(100);
}
void loop()
{

    i2c_MasterTransmit(8,"TuanDat");
   delay(100);
}

















