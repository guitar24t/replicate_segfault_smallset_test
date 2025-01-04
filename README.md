# Replicate a Segfault occurring in Pathlpannerlib via the wpilib SmallSet destructor

Stack trace:
```
#1  0x0000aaaaaae9edc4 in free ()
#2  0x0000aaaaaaf454b4 in wpi::SmallPtrSetImplBase::~SmallPtrSetImplBase() ()
#3  0x0000aaaaaaf456a4 in wpi::SmallPtrSetImpl<frc2::Subsystem*>::~SmallPtrSetImpl() ()
#4  0x0000aaaaaaf456c4 in wpi::SmallPtrSet<frc2::Subsystem*, 4u>::~SmallPtrSet() ()
#5  0x0000aaaaaaf456e4 in wpi::SmallSet<frc2::Subsystem*, 4u, std::less<frc2::Subsystem*> >::~SmallSet() ()
#6  0x0000aaaaaaf582d8 in pathplanner::EventScheduler::getSchedulerRequirements(std::shared_ptr<pathplanner::PathPlannerPath>) ()
#7  0x0000aaaaaaf530b4 in pathplanner::FollowPathCommand::FollowPathCommand(std::shared_ptr<pathplanner::PathPlannerPath>, std::function<frc::Pose2d ()>, std::function<frc::ChassisSpeeds ()>, std::function<void (frc::ChassisSpeeds const&, pathplanner::DriveFeedforwards const&)>, std::shared_ptr<pathplanner::PathFollowingController>, pathplanner::RobotConfig, std::function<bool ()>, frc2::Requirements) ()
```

You can run this cmake project inside our docker container for testing: guitar24t/ck-ros2 which has the wpilib 2025.1.1 library installed
