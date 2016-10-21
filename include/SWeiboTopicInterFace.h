#ifndef __S_WEIBO_TOPIC_INTERFACE_H__
#define __S_WEIBO_TOPIC_INTERFACE_H__

#include "DataType.h"

const string MyVersion   = "WeiboTDT_Version_1.0.0";
const string MyBuildTime = ("WeiboTDT_Build_Time_"__DATE__" "__TIME__);

typedef void WTI;

namespace WeiboTopic_ICT
{

	/*!
	*  \fn		WTI* WTI_Open(const char *config)
	*  \brief	open weibo TDT handle
	*  \param [in]	config			configure file name
	*  \return		WTI handle
	*  \author	chenqiang(chenqiang@software.ict.ac.cn)
	*  \date	2013-12-09
	*/
	WTI* WTI_Open(const char *config);
	
	/*!
	*  \fn		int WTI_GetResult(WTI *wtihandler, vector<Weibo> &weibo, vector<User> &users, vector<Topic> &topics)
	*  \brief	to get weibo topics
	*  \param [in]	wtihandler		weibo TDT handle
	*  \param [in]	weibo			weibodata
	*  \param [in]	users			user data
	*  \param [out]	topics			topics result
	*  \return		the topics num
	*  \author	chenqiang(chenqiang@software.ict.ac.cn)
	*  \date	2013-12-09
	*/
	int WTI_GetResult(WTI *wtihandler, vector<Weibo> &weibo, vector<User> &users, vector<Topic> &topics);

	/*!
	*  \fn		WTI WTI_Close(WTI *wtihandler);
	*  \brief	free weibo TDT handle
	*  \param [in]	wtihandler			weibo TDT handle to free
	*  \return		WTI
	*  \author	chenqiang(chenqiang@software.ict.ac.cn)
	*  \date	2013-12-09
	*/
	WTI WTI_Close(WTI *wtihandler);
}

#endif
