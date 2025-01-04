#include <wpi/SmallSet.h>
#include <frc2/command/Subsystem.h>
#include <frc2/command/Command.h>
#include <iostream>
#include <pathplanner/lib/events/EventScheduler.h>

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