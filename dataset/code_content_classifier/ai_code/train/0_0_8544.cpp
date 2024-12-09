#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Project {
    string name;
    int version;
    set<string> dependencies;
};

map<string, Project> projects;
map<string, Project> resolvedProjects;

void resolveDependencies(string projectName, int projectVersion) {
    if (resolvedProjects.count(projectName) > 0) {
        if (resolvedProjects[projectName].version >= projectVersion) {
            return;
        }
    }

    resolvedProjects[projectName] = projects[projectName];

    for (string dependency : projects[projectName].dependencies) {
        resolveDependencies(dependency, projects[dependency].version);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int version;
        cin >> name >> version;

        Project project;
        project.name = name;
        project.version = version;

        int numDependencies;
        cin >> numDependencies;

        for (int j = 0; j < numDependencies; j++) {
            string dependencyName;
            int dependencyVersion;
            cin >> dependencyName >> dependencyVersion;

            project.dependencies.insert(dependencyName);

            if (projects.count(dependencyName) == 0 || projects[dependencyName].version < dependencyVersion) {
                Project depProject;
                depProject.name = dependencyName;
                depProject.version = dependencyVersion;
                projects[dependencyName] = depProject;
            }
        }

        projects[name] = project;
    }

    resolveDependencies(projects.begin()->first, projects.begin()->second.version);

    resolvedProjects.erase(projects.begin()->first);

    for (auto it = resolvedProjects.begin(); it != resolvedProjects.end(); ++it) {
        cout << it->second.name << " " << it->second.version << endl;
    }

    return 0;
}