/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 #define MAX_ROOMS 5  // Max number of rooms
 
 // Global arrays to store states
 int lights[MAX_ROOMS] = {0}; // 0 = OFF, 1 = ON
 int temperatures[MAX_ROOMS] = {22, 24, 23, 25, 21}; // Sample temperatures
 int motionSensors[MAX_ROOMS] = {0}; // 0 = No motion, 1 = Motion detected
 int securityLocks[MAX_ROOMS] = {1}; // 1 = Locked, 0 = Unlocked
 
 // Function prototypes
 void initializeSystem();
 void displayMenu();
 void controlLights();
 void readTemperature();
 void detectMotion();
 void securitySystem();
 void analyzeHouseStatus();
 
 int main() {
     initializeSystem();
     int choice;
     do {
         displayMenu();
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1: controlLights(); break;
             case 2: readTemperature(); break;
             case 3: detectMotion(); break;
             case 4: securitySystem(); break;
             case 5: analyzeHouseStatus(); break;
             case 6: printf("Exiting program...\n"); break;
             default: printf("Invalid choice! Try again.\n");
         }
     } while (choice != 6);
     
     return 0;
 }
 
 void initializeSystem() {
     for (int i = 0; i < MAX_ROOMS; i++) {
         lights[i] = 0;
         motionSensors[i] = 0;
         securityLocks[i] = 1;
     }
     printf("System initialized: Lights OFF, Motion sensors OFF, All doors LOCKED.\n");
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 
 void controlLights() {
     int room;
     printf("Enter room number (1-%d) to toggle light: ", MAX_ROOMS);
     scanf("%d", &room);
     if (room >= 1 && room <= MAX_ROOMS) {
         lights[room - 1] = !lights[room - 1];
         printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void readTemperature() {
     int room;
     printf("Enter room number (1-%d) to read temperature: ", MAX_ROOMS);
     scanf("%d", &room);
     if (room >= 1 && room <= MAX_ROOMS) {
         printf("Temperature in Room %d: %d°C\n", room, temperatures[room - 1]);
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void detectMotion() {
     int room;
     printf("Enter room number (1-%d) to check motion: ", MAX_ROOMS);
     scanf("%d", &room);
     if (room >= 1 && room <= MAX_ROOMS) {
         printf("Motion in Room %d: %s\n", room, motionSensors[room - 1] ? "Detected" : "No Motion");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void securitySystem() {
     int room;
     printf("Enter room number (1-%d) to lock/unlock: ", MAX_ROOMS);
     scanf("%d", &room);
     if (room >= 1 && room <= MAX_ROOMS) {
         securityLocks[room - 1] = !securityLocks[room - 1];
         printf("Door in Room %d is now %s.\n", room, securityLocks[room - 1] ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void analyzeHouseStatus() {
     printf("\nHouse Status:\n");
     for (int i = 0; i < MAX_ROOMS; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
                i + 1, lights[i] ? "ON" : "OFF", temperatures[i], 
                motionSensors[i] ? "Motion Detected" : "No Motion", 
                securityLocks[i] ? "Locked" : "Unlocked");
     }
 }
 
