#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string name, bio;
    int numSkills, numProjects;
    vector<string> skills, projectNames, projectDesc;

    // Input user details
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Write a short bio/about yourself: ";
    getline(cin, bio);

    cout << "How many skills do you want to add? ";
    cin >> numSkills;
    cin.ignore(); // clear buffer

    for(int i=0; i<numSkills; i++) {
        string skill;
        cout << "Enter skill " << i+1 << ": ";
        getline(cin, skill);
        skills.push_back(skill);
    }

    cout << "How many projects do you want to add? ";
    cin >> numProjects;
    cin.ignore();

    for(int i=0; i<numProjects; i++) {
        string pname, pdesc;
        cout << "Enter project " << i+1 << " name: ";
        getline(cin, pname);
        cout << "Enter project " << i+1 << " description: ";
        getline(cin, pdesc);
        projectNames.push_back(pname);
        projectDesc.push_back(pdesc);
    }

    // Create index.html
    ofstream html("index.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n";
    html << "<title>" << name << "'s Portfolio</title>\n";
    html << "<link rel=\"stylesheet\" href=\"style.css\">\n</head>\n<body>\n";
    html << "<div class='container'>\n";
    html << "<h1>" << name << "</h1>\n";
    html << "<p class='bio'>" << bio << "</p>\n";

    // Skills section
    html << "<h2>Skills</h2>\n<ul>\n";
    for(string s : skills) {
        html << "<li>" << s << "</li>\n";
    }
    html << "</ul>\n";

    // Projects section
    html << "<h2>Projects</h2>\n";
    for(int i=0; i<numProjects; i++) {
        html << "<div class='project'>\n<h3>" << projectNames[i] << "</h3>\n";
        html << "<p>" << projectDesc[i] << "</p>\n</div>\n";
    }

    html << "</div>\n</body>\n</html>";
    html.close();

    // Create style.css
    ofstream css("style.css");
    css << "body { font-family: Arial, sans-serif; background: #f4f4f9; color: #333; }\n";
    css << ".container { width: 70%; margin: auto; background: white; padding: 20px; border-radius: 10px; box-shadow: 0px 0px 10px gray; }\n";
    css << "h1 { color: #007acc; }\n";
    css << ".bio { font-style: italic; margin-bottom: 20px; }\n";
    css << "ul { list-style-type: square; }\n";
    css << ".project { background: #eef; padding: 10px; margin: 10px 0; border-left: 5px solid #007acc; }\n";
    css.close();

    cout << "✅ Portfolio website generated successfully! Open index.html in your browser.\n";
    return 0;
}
