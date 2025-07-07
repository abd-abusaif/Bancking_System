#pragma once
#include <sstream>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include <string.h>

class Parser
{
public:

	static vector<string> split_sentence(string sen) {

		stringstream lineStream(sen);

		// Variable to hold facth each word
		string segment;

		vector<string> splitResults;

		//Extract words from the sentence
		while (getline(lineStream, segment, '-')) {

			// Add the segement to the vector
			splitResults.push_back(segment);
		}

		return splitResults;
	}


	static Client parserToClient(string line) {

		vector<string> parsedData = Parser::split_sentence(line);
		
		return Client(stoi(parsedData[0]), parsedData[1], parsedData[2], stod(parsedData[3]));
	}

	static Employee parserToEmployee(string line) {

		vector<string> parsedData = Parser::split_sentence(line);


		return Employee(stoi(parsedData[0]), parsedData[1], parsedData[2], stod(parsedData[3]));
	}

	static Admin parserToAdmin(string line) {

		vector<string> parsedData = Parser::split_sentence(line);


		return Admin(stoi(parsedData[0]), parsedData[1], parsedData[2], stod(parsedData[3]));
	}
};

