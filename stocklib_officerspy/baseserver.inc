#if defined _stock_officerspy_baseserver_included
	#endinput
#endif
#define _stock_officerspy_baseserver_included

#define MAX_TAG_STRING_LENGTH		128

stock void BaseServer_AddTag(const char[] pszTag)
{
	char serverTags[MAX_TAG_STRING_LENGTH]; FindConVar("sv_tags").GetString(serverTags, sizeof(serverTags));
	
	char tagList[10][21];
	int tagListCount = ExplodeString(serverTags, ",", tagList, sizeof(tagList), sizeof(tagList[]));
	
	for (int i = 0; i < tagListCount; i++)
	{
		//Tag already exists
		if (!strcmp(tagList[i], pszTag, false))
			return;
	}
	
	//Append tag
	char tmpTags[MAX_TAG_STRING_LENGTH];
	tmpTags[0] = '\0';
	strcopy(tmpTags, MAX_TAG_STRING_LENGTH, pszTag);
	StrCat(tmpTags, MAX_TAG_STRING_LENGTH, ",");
	StrCat(tmpTags, MAX_TAG_STRING_LENGTH, serverTags);
	FindConVar("sv_tags").SetString(tmpTags);
}

stock void BaseServer_RemoveTag(const char[] pszTag)
{
	char pszTags[MAX_TAG_STRING_LENGTH]; FindConVar("sv_tags").GetString(pszTags, sizeof(pszTags));
	
	//No tags to remove
	if (IsNullString(pszTags) || !pszTags[0])
		return;
	
	char tmpTags[MAX_TAG_STRING_LENGTH];
	tmpTags[0] = '\0';
	
	char tagList[10][21];
	int tagListCount = ExplodeString(pszTags, ",", tagList, sizeof(tagList), sizeof(tagList[]));
	bool bFoundIt = false;
	
	for (int i = 0; i < tagListCount; i++)
	{
		//Keep any tags other than the specified one
		if (strcmp(tagList[i], pszTag, false))
		{
			StrCat(tmpTags, MAX_TAG_STRING_LENGTH, tagList[i]);
			StrCat(tmpTags, MAX_TAG_STRING_LENGTH, ",");
		}
		else
		{
			bFoundIt = true;
		}
	}
	
	//We couldn't find the tag to remove
	if (!bFoundIt)
		return;
	
	FindConVar("sv_tags").SetString(tmpTags);
}