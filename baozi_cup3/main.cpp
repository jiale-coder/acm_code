#include "glog/logging.h"
#include "gflags/gflags.h"

DEFINE_string(log_name, "baozi_cup3", "日志名字");

int main(int argc, char* argv[]) {
  // 初始化 glog
  google::InitGoogleLogging(argv[0]);
  FLAGS_stderrthreshold = 0;
  
  // 输出不同级别的日志
  LOG(INFO) << "Log name: " << FLAGS_log_name;
  LOG(INFO) << "This is an INFO log (glog works!)";
  LOG(WARNING) << "This is a WARNING log";
  LOG(ERROR) << "This is an ERROR log";
  
  // 关闭 glog
  google::ShutdownGoogleLogging();
  return 0;
}