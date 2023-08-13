#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
//------------------------------------------------------------------------------------------

class Player {
 private:
  bool play = false;
  bool pause = false;

  class Track {

   public:
    std::vector<std::string> nameTrack{"One", "Two", "Three"};
    std::vector<int> timeTrack{100, 108, 96};
    std::vector<int> dateTrack{1986, 2001, 2012};
  };
 public:
Track track_;
  //----------------------------------------------------------------------------
  void Play(std::string &name) {

    if (!play) {
      for (int i = 0; (i <track_.nameTrack.size()); ++i) {
        if (track_.nameTrack[i] == name) {
          std::cout << "Track name: " << track_.nameTrack[i] << ". "
                    << "Track time: " << track_.timeTrack[i] << " sec. "
                    << "Track date: " << track_.dateTrack[i] << " year." << std::endl;
          play = true;
          break;
        }
      }
      if (!play)
        std::cout << "This track is not." << std::endl;
    } else if (pause) pause = false;
  }
  //----------------------------------------------------------------------------
  void Pause() {
    if (play && !pause) {
      std::cout << "-------PAUSE--------" << std::endl;
      pause = true;
    } else return;
  }
  //----------------------------------------------------------------------------
  void Stop() {
    if (play) {
      std::cout << "Playback stopped." << std::endl;
      play = false;
    } else return;
  }
  //----------------------------------------------------------------------------
  void Next() {
    if (play) {
      int ind;
      srand(time(nullptr));
      ind = rand() % track_.nameTrack.size();
      std::cout << "Track name: " << track_.nameTrack[ind] << ". "
                << "Track time: " << track_.timeTrack[ind] << " sec. "
                << "Track date: " << track_.dateTrack[ind] << " year." << std::endl;
      pause = false;
    }
  }
};
int command(std::string &command) {
  if (command == "play") return 1;
  else if (command == "pause") return 2;
  else if (command == "next") return 3;
  else if (command == "stop") return 4;
  else if (command == "exit") return 5;
  else return 0;
}

int main() {
  Player player;
  std::string str;
  do {
    std::cout << "Enter command: " << std::endl
              << "<play> <pause> <next> <stop> or <exit> " << std::endl;
    std::cin >> str;
    switch (command(str)) {
      case 1://if play
          std::cout << "Enter name track: ";
          std::cin >> str;
          player.Play(str);
        break;
      case 2://if pause
        player.Pause();
        break;
      case 3://if next
        player.Next();
        break;
      case 4://if stop
        player.Stop();
        break;
      case 5://if exit
        std::cout << "Work finished." << std::endl;
        break;
      case 0:// if enter error
        std::cout << "Enter error. Repeat, please. " << std::endl;
        break;
    }
  } while (str != "exit");
  return 0;
}
