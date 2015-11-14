#include <iostream>
#include "include\leveldb\db.h"
using namespace leveldb;
using namespace std;

void main()
{
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "tmp/testdb", &db);
	if (status.ok()){
		string s("hello");
		Slice key1(s);
		string value;
		status = db->Put(leveldb::WriteOptions(), key1, value);
		delete db;
	}

	system("pause");
}