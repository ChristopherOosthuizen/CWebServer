#include "Model.h"
string forOfor(HTTPResponse response){
    HTTPRequest request("no page",404,"No page found");
    return request.toString();
}
Model::Model(function<string(HTTPResponse)> func,const string& method) {
	m_methods[method] = func;
}

function<string(HTTPResponse)> Model::searchPath(const string& str,const string& method)
{
	if (str.empty()) {
	    return m_methods[method] ;
    }


	int current = str.find("/");
	if (current == -1) {
	    if(m_paths[str] != NULL)
	        return m_paths[str]-> m_methods[method];
	    return forOfor;
	}
	else {
		string key = str.substr(0, current);
		return m_paths[key]->searchPath(str.substr(current+1,str.length()),method);
	}
}

void Model::add(const string& str,const string& method, function<string(HTTPResponse)> func)
{
	//if the key does not have a / assume that thats the final poition
	int current = str.find("/");
	if (current == -1) {
		m_paths[str] = new Model(func,method);
	}
	//if it does contain a / add a new node and add another model to the tree
	else {
		Model* mod;
		string key = str.substr(0, current);
		//if the key is nulll try the universal identifier else just break
		if (m_paths[key] != NULL) {
			mod = m_paths[key] ;
		}
		else if (m_paths["%"] != NULL) {
			mod = m_paths["%"] ;
		}
		else {
			mod = new Model(forOfor,method);
			m_paths[key] = mod;
		}
		mod->add(str.substr(current+1,str.length()),method, func);
	}

}
