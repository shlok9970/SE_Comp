#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Job structure
struct Job {
    int jobId;
    string jobName;

    Job(int id, const string& name) : jobId(id), jobName(name) {}
};

// Class to represent the Job Queue
class JobQueue {
private:
    queue<Job> jobQueue; // Standard queue to hold jobs
    int nextJobId; // To keep track of the next job ID

public:
    JobQueue() : nextJobId(1) {} // Initialize nextJobId to 1

    // Function to add a job to the queue
    void addJob(const string& jobName) {
        Job newJob(nextJobId++, jobName); // Create a new job with a unique ID
        jobQueue.push(newJob); // Add the job to the queue
        cout << "Job added: ID = " << newJob.jobId << ", Name = " << newJob.jobName << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue to delete." << endl;
            return;
        }
        Job deletedJob = jobQueue.front(); // Get the job at the front of the queue
        jobQueue.pop(); // Remove the job from the queue
        cout << "Job deleted: ID = " << deletedJob.jobId << ", Name = " << deletedJob.jobName << endl;
    }

    // Function to display the current jobs in the queue
    void displayJobs() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue." << endl;
            return;
        }
        cout << "Current jobs in the queue:" << endl;
        queue<Job> tempQueue = jobQueue; // Create a temporary queue to display jobs
        while (!tempQueue.empty()) {
            Job job = tempQueue.front();
            cout << "ID = " << job.jobId << ", Name = " << job.jobName << endl;
            tempQueue.pop();
        }
    }
};

int main() {
    JobQueue jobQueue; // Create a JobQueue object
    int choice;
    string jobName;

    do {
        cout << "\nJob Queue Menu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, jobName); // Read the job name
                jobQueue.addJob(jobName); // Add the job to the queue
                break;
            case 2:
                jobQueue.deleteJob(); // Delete a job from the queue
                break;
            case 3:
                jobQueue.displayJobs(); // Display current jobs in the queue
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
