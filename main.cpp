#include <wpi/SmallSet.h>
#include <frc2/command/Subsystem.h>
#include <frc2/command/Command.h>
#include <iostream>
#include <pathplanner/lib/events/EventScheduler.h>

//Lightly replicate the conditions of the FollowPathCommand causing SIGSEGV from 
//https://github.com/mjansen4857/pathplanner/blob/main/pathplannerlib/src/main/native/cpp/pathplanner/lib/commands/FollowPathCommand.cpp#L30
class FollowPathCommand: public frc2::CommandHelper<frc2::Command, FollowPathCommand> {
public:
    static inline wpi::SmallSet<frc2::Subsystem*, 4>  retThis()
    {
        wpi::SmallSet<frc2::Subsystem*, 4> allReqs;
        wpi::SmallSet<frc2::Subsystem*, 4> requirements;
        allReqs.insert(requirements.begin(), requirements.end());
        return allReqs;
    }

    void doTest()
    {
        std::cout << "Before me: " << std::endl;
        {
            auto allReqs = retThis();
            AddRequirements(allReqs);
        }
        std::cout << "After me: " << std::endl;
    }
};

int main()
{
    FollowPathCommand fpc;
    fpc.doTest();
    return 0;
}