#cvm-runner.exe:$(cvm-req)

#.PHONY:build-cvm-runner
build-cyv:$(cyv-dir)main.cpp $(cvm-req) $(BUILD_DIR)/cvm$(DLL_OUT_TYPE)
	g++ $(BUILD_DIR)/cvm$(DLL_OUT_TYPE) $(cyv-dir)main.cpp $(char_set) -o $(BUILD_DIR)/cyv$(FILE_OUT_TYPE)
#$(make) cvm-runner.exe
