/*************************************************************************
 > File Name: test.cpp
 > Author: zhounan
 > Mail: scutzhounan@foxmail.com
 > Created Time: Thu 10 Sep 2015 02:51:16 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include"const.h"
#include"util.h"
#include"plsa.h"
//#include"ictlap_plugin_event.h"
#include<pthread.h>
#include"subtopic.h"
using namespace std;
using namespace WeiboTopic_ICT;

void save(vector<Topic> topic_list, string root)
{
	for (int i = 0; i < topic_list.size(); ++i)
	{
		char cid[10];
		string filename;
		sprintf(cid, "%d", i);
		filename = root + "/" + cid;
		ofstream out(filename.c_str());
		vector<Weibo> docs = topic_list[i].weibovec;
		for (int j = 0; j < docs.size(); ++j)
			out << docs[j].mt << endl;
		out.close();
	}
}


int main(int argc, char **argv)
{
	/*google::InitGoogleLogging("SubTopic");
	google::SetStderrLogging(google::ERROR);
	google::SetLogDestination(google::GLOG_INFO,"../log/");
	FLAGS_colorlogtostderr=true;*/
	//string conf_path = "../conf/plsa_conf.xml";
	//string local_path = "/home/zhounan/corpus/mongo_data/explosion_text";
	//string local_path = "/home/zhounan/sogou_text";
	string local_path = argv[1];
    cout<<local_path<<endl;
	vector<WeiboTopic_ICT::Weibo> doc_list;
	vector<WeiboTopic_ICT::Topic> topic_list;
	tools::UtilInterface::read_text_from_local(local_path, doc_list);
    string conf_path = "/home/zhounan/project/subtopic/conf/plsa_conf.xml";
    cout<<"ok"<<endl;
	ict::CSubTopic sub_topic(conf_path);

	/*subtopic_param param;
	param.docs = doc_list;
	param.topics = topic_list;
	param.thresh = 2;
	param.min_count = 3;
	param.match_rate = 0.5;
	ICTLAP_TOPIC_PARAM ict_param = &param;


	ICTLAP_PLUGIN_HANDLE handle = ICTLAP_TOPIC_Event_Init("/home/zhounan/project/subtopic/");
	ICTLAP_TOPIC_RESULT result = ICTLAP_TOPIC_Event_Run(handle, ict_param, NULL);*/
    cout<<"ok2"<<endl;
	sub_topic.generate_sub_topics(doc_list, topic_list, 2, 3, 0.5);
	//string root = argv[2];
	//save(, root);

	//ICTLAP_TOPIC_Event_ReleaseResult(handle, result, ict_param);
    //ICTLAP_TOPIC_Event_Exit(handle);

	return 0;
}

