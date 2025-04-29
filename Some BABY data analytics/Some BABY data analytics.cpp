// Some BABY data analytics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<fstream>
#include <iostream>
#include<string> 
#include <vector>
#include <cassert>

struct MusicRecord
{
	std::string title; 
	std::string artist; 
	std::string genre; 
	int bpm; //ex: 90 beats per minute
	int numberOfPlays; 
	int year; 
};

/*This is me reinventing the wheel
* @param startIndex and endIndex -> substring returned is INCLUSIVE of these indices 
*/
std::string getSubstring(const std::string& originalString, int startIndex, int endIndex)
{
	assert(startIndex >= 0 && startIndex < originalString.length());
	assert(endIndex >= 0 && endIndex < originalString.length());

	std::string substring; 
	for (int i = startIndex; i <= endIndex; ++i)
	{
		substring.push_back(originalString[i]);
	}

	return substring; 
}

MusicRecord getMusicRecordFromStringParsing(const std::string& stringMusicRecord)
{
	//get the locations of all commas (which mark the end of a particular column in a CSV file): 
	std::vector<int> commaLocations; 
	//commaLocations.push_back(0); //There IS no comma at index 0 - using this for "convenience" below
	for (int i = 0; i < stringMusicRecord.size(); ++i)
	{
		if (stringMusicRecord[i] == ',')
			commaLocations.push_back(i); 
	}

	//now get the substrings BETWIXT all commas: 
	std::vector<std::string> substrings; 

	//the first field (song title) is a "special case" (so I am not finding it with the loop below):
	int startPosition = 0;
	int endPosition = commaLocations[0] - 1;

	std::string substring = getSubstring(stringMusicRecord, startPosition, endPosition);
	substrings.push_back(substring); 

	/*Now get the remaining fields (except the last one)*/
	for (int i = 0; i < commaLocations.size() - 1; ++i)
	{
		startPosition = commaLocations[i] + 1; 
		endPosition = commaLocations[i + 1] - 1;

		substring = getSubstring(stringMusicRecord, startPosition, endPosition);
		substrings.push_back(substring);
	}

	/*Now the last field (another "special" case):*/
	startPosition = commaLocations[commaLocations.size() - 1] + 1; 
	endPosition = stringMusicRecord.size() - 1; 
	substrings.push_back(getSubstring(stringMusicRecord, startPosition, endPosition)); //reduced to one line - compared to above in loop

	MusicRecord currentRecord =
	{
		substrings[0], //title 
		substrings[1], //artist
		substrings[2], //genre
		std::stoi(substrings[3]), //beats per minute
		std::stoi(substrings[4]), //number of plays
		std::stoi(substrings[5]) //year
	};
	
	return currentRecord;

}

float getAverageBeatsPerMinute(const std::vector<MusicRecord>& musicRecords)
{
	float summedBPM = 0.0f; 
	for (const auto& record : musicRecords)
		summedBPM += record.bpm;

	return (summedBPM / musicRecords.size());
}

/*Recall -> dynamic arrays can grow and shrink as needed*/
std::vector<MusicRecord> readFileAndFillData(std::string filename)
{
	std::ifstream fin(filename); 
	if (!fin) 
	{
		std::cout << "File " << filename << " not found :(\n";
		return {}; //this is the "empty vector" -> similar to the empty string ""
	}

	std::vector<MusicRecord> musicRecords; 
	std::string currentLine;

	while (std::getline(fin, currentLine))
	{
		MusicRecord currentRecord = getMusicRecordFromStringParsing(currentLine); 

		musicRecords.push_back(currentRecord); 
	}

	return musicRecords; 
}



int main()
{
	std::string filename = "MusicData.txt";
	auto musicRecords = readFileAndFillData(filename);

	std::cout << "Average beats per minute in this playlist: \n";
	std::cout << getAverageBeatsPerMinute(musicRecords) << "\n";

}

