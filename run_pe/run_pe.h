#pragma once

#include <Windows.h>
#include <stdio.h>

#include "ntddk.h"

bool create_new_process(IN LPSTR path, OUT PROCESS_INFORMATION &pi);

bool get_remote_context(PROCESS_INFORMATION &pi, CONTEXT &context);

ULONGLONG get_remote_peb_addr(const CONTEXT &context);

bool read_remote_mem(HANDLE hProcess, ULONGLONG remote_addr, OUT void* buffer, const size_t buffer_size);

bool redirect_to_payload(BYTE* loaded_pe, PVOID load_base, PROCESS_INFORMATION &pi, CONTEXT &context);

void make_gui_subsystem(BYTE* loaded_pe);

bool run_pe(char *payloadPath, char *targetPath);