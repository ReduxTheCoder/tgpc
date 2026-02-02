/*
 * TGPC - Command-line project scaffolder
 * Copyright (c) 2026 ReduxTheCoder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * File: <lib.rs>
*/
use std::ffi::CStr;
use std::os::raw::c_char;

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ConfigCmd {
    CONFIG_SET = 0,
    CONFIG_SHOW,
    NOT_GIVEN,
}

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum TgpcCommand {
    COMMAND_NEW = 0,
    COMMAND_HELP,
    COMMAND_RUN,
    COMMAND_CONFIG,
    COMMAND_DATA,
    COMMAND_UPDATE,
    COMMAND_UNKNOWN,
}

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ProgrammingLanguage {
    C = 0,
    CPP,
    PYTHON,
    JAVA,
    RUST,
    ASM,
    JS,
    TS,
    RB,
    GO,
    PHP,
    INVALID,
}

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub enum ConfigFile {
    CONFIG_RUN,
    NONE,
}

#[unsafe(no_mangle)]
pub extern "C" fn get_tgpc_command_from_str_rust(cmd: *const c_char) -> TgpcCommand {
    if cmd.is_null() {
        return TgpcCommand::COMMAND_UNKNOWN;
    }

    let c_str = unsafe { CStr::from_ptr(cmd) };
    let str_slice = match c_str.to_str() {
        Ok(s) => s,
        Err(_) => return TgpcCommand::COMMAND_UNKNOWN,
    };

    match str_slice {
        "h" | "help" => TgpcCommand::COMMAND_HELP,
        "r" | "run" => TgpcCommand::COMMAND_RUN,
        "c" | "config" => TgpcCommand::COMMAND_CONFIG,
        "n" | "new" => TgpcCommand::COMMAND_NEW,
        "d" | "data" => TgpcCommand::COMMAND_DATA,
        _ => TgpcCommand::COMMAND_UNKNOWN,
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn get_language_enum_from_str_rust(lang: *const c_char) -> ProgrammingLanguage {
    if lang.is_null() {
        return ProgrammingLanguage::INVALID;
    }

    let c_str = unsafe { CStr::from_ptr(lang) };
    let str_slice = match c_str.to_str() {
        Ok(s) => s,
        Err(_) => return ProgrammingLanguage::INVALID,
    };

    match str_slice {
        "c" => ProgrammingLanguage::C,
        "cpp" => ProgrammingLanguage::CPP,
        "py" => ProgrammingLanguage::PYTHON,
        "java" => ProgrammingLanguage::JAVA,
        "rs" => ProgrammingLanguage::RUST,
        "asm" => ProgrammingLanguage::ASM,
        "js" => ProgrammingLanguage::JS,
        "ts" => ProgrammingLanguage::TS,
        "rb" => ProgrammingLanguage::RB,
        "go" => ProgrammingLanguage::GO,
        "php" => ProgrammingLanguage::PHP,
        _ => ProgrammingLanguage::INVALID,
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn get_enum_config_from_str_rust(config: *const c_char) -> ConfigFile {
    if config.is_null() {
        return ConfigFile::NONE;
    }

    let c_str = unsafe { CStr::from_ptr(config) };
    let str_slice = match c_str.to_str() {
        Ok(s) => s,
        Err(_) => return ConfigFile::NONE,
    };

    match str_slice {
        "run" => ConfigFile::CONFIG_RUN,
        _ => ConfigFile::NONE,
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn get_enum_config_cmd_from_str_rust(cmd: *const c_char) -> ConfigCmd {
    if cmd.is_null() {
        return ConfigCmd::NOT_GIVEN;
    }

    let c_str = unsafe { CStr::from_ptr(cmd) };
    let str_slice = match c_str.to_str() {
        Ok(s) => s,
        Err(_) => return ConfigCmd::NOT_GIVEN,
    };

    match str_slice {
        "w" | "set" => ConfigCmd::CONFIG_SET,
        "s" | "show" => ConfigCmd::CONFIG_SHOW,
        _ => ConfigCmd::NOT_GIVEN,
    }
}
