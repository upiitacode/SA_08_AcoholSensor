#include "gmock/gmock.h"
#include "serial_stream.h"
using ::testing::Eq;
using ::testing::StrEq;

class Mock_stream : public Serial_stream{
	public:
		const char* intenalInputBuffer;
		char  intenalOutputBuffer[90];
		int  inBuffIndex = 0;
		int  outBuffIndex = 0;
		char getChar(void){
			char inputChar  = intenalInputBuffer[inBuffIndex];
			inBuffIndex++;
			return  inputChar;
		}
		void sendChar(char outputChar){
			intenalOutputBuffer[outBuffIndex] = outputChar;
			intenalOutputBuffer[outBuffIndex+1] = '\0';
			outBuffIndex++;
		}
};

TEST(SerialStream,SerialGetsReadsFromGetChar){
	Mock_stream myMock;
	char readData[80];
	myMock.intenalInputBuffer = "Hello\r";
	myMock.gets(readData,80);
	ASSERT_THAT(readData,StrEq("Hello"));
}

TEST(SerialStream,SerialPutsWritesToSendChar){
	Mock_stream myMock;
	char writeData[] = "HelloMock";
	myMock.puts(writeData);
	ASSERT_THAT(myMock.intenalOutputBuffer,StrEq("HelloMock"));
}


TEST(SerialStream,SerialPrintfWritesToSendChar){
	Mock_stream myMock;
	myMock.printf("HelloMock");
	ASSERT_THAT(myMock.intenalOutputBuffer,StrEq("HelloMock"));
}
