# Atmel
>Requires: Modules/Platforms/Common


To use with an atmel asf project, include the Mr T repo as a submodule of the project
>(for more detailed instruction visit the README from the MrT/Config Repo)

**Integrating to Atmel Studio**

Once you have created your project and imported the Mr T modules needed, open the project in Atmel Studio and follow these steps:

1. Click the 'Show All files' button in the solution explorer
2. right click mrt/Modules/mrt_platform, and select 'Include in project'
3. go to the poject properties and add the symbol for your framework
> **MRT_PLATFORM_ATMEL_ASF** for atmel asf projects<br/>
> **MRT_PLATFORM_ATMEL_START** for atmel-start projects
4. go to the poject properties and add 'src/mrt/Modules' as an include path
5. for each module you would like to use, right click the module directory in the solution explorer, and click 'Include in project'
