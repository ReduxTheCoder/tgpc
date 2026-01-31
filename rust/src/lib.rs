// src/lib.rs
use std::ffi::CStr;
use std::os::raw::c_char;

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
    CONFIG_RUN = 0,
    NONE,
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
