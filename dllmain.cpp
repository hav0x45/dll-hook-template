#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <thread>
#include <cstdint>

// Setup function
void Setup(const HMODULE instance) {

}

// Entry point
BOOL WINAPI DllMain(const HMODULE instance, const std::uintptr_t reason, const void* reserved) {

    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(instance);

        const auto MyThread = CreateThread(nullptr,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(Setup),
            instance,
            0,
            nullptr);

        if (MyThread) {
            CloseHandle(MyThread);
        }
    }

    return true;
};